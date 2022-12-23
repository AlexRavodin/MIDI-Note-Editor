#include "NoteParser.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

UInt64 ConvertBytesToNumber(List<Byte>^ bytes) {
	UInt64 number = 0;
	for (int i = 0; i < bytes->Count; i++)
		number = (number << 8) | bytes[i];
	return number;
}

MIDIEvent^ FindNoteOff(UInt16 noteHeight, List<MIDIEvent^>^ midiEvents, int currentPosition) {
	for (int i = currentPosition; i < midiEvents->Count; i++)
		if (midiEvents[i]->Status == MIDIStatus::NOTE_OFF && midiEvents[i]->FirstParam == noteHeight)
			return midiEvents[i];
	throw "gg note off";
	return nullptr;
}

NoteParser::NoteParser() {}

NoteParser::NoteParser(MIDIParser^ midiParser) {
	this->midiParser = midiParser;
	TimeDivision = midiParser->GetTimeDivision();
	NoteLines = gcnew List<NoteLine^>();
	SetTempos = gcnew List<SetTempo^>();
	GetSetTempos(midiParser);
	TimeSignatures = gcnew List<TimeSignature^>();
	GetTimeSignatures(midiParser);
	Convert();
}

void NoteParser::GetTimeSignatures(MIDIParser^ midiParser) {
	for (int i = 0; i < midiParser->Tracks->Count; i++) {
		MIDITrack^ midiTrack = midiParser->Tracks[i];
		List<MIDIMetaEvent^>^ metaEvents = midiTrack->GetMetaEvents();
		for (int j = 0; j < metaEvents->Count; j++) {
			if (metaEvents[j]->Type == MIDIMeta::TIME_SIGNATURE) {
				TimeSignature^ timeSignature = gcnew TimeSignature();
				timeSignature->StartTick = metaEvents[j]->MIDITime;
				timeSignature->Numerator = (int)metaEvents[j]->GetData()[0];
				timeSignature->Denumerator = System::Math::Pow(2, (int)metaEvents[j]->GetData()[1]);
				TimeSignatures->Add(timeSignature);
			}
		}
	}
}

void NoteParser::GetSetTempos(MIDIParser^ midiParser) {
	for (int i = 0; i < midiParser->Tracks->Count; i++) {
		MIDITrack^ midiTrack = midiParser->Tracks[i];
		List<MIDIMetaEvent^>^ metaEvents = midiTrack->GetMetaEvents();
		for (int j = 0; j < metaEvents->Count; j++) {
			if (metaEvents[j]->Type == MIDIMeta::SET_TEMPO) {
				SetTempo^ setTempo = gcnew SetTempo();
				setTempo->StartTick = metaEvents[j]->MIDITime;
				setTempo->TPQ = ConvertBytesToNumber(metaEvents[j]->GetData());
				SetTempos->Add(setTempo);
			}
		}
	}
}

SetTempo^ NoteParser::GetSetTempo(UInt64 MIDITime) {
	bool isNotFound = true;
	SetTempo^ setTempo;
	if (SetTempos->Count == 1) {
		setTempo = SetTempos[0];
	}
	else {
		for (int i = 0; (i < (SetTempos->Count - 1) && isNotFound); i++) {
			if (SetTempos[i]->StartTick <= MIDITime && MIDITime < SetTempos[i + 1]->StartTick) {
				setTempo = SetTempos[i];
				isNotFound = false;
			}
			else
				setTempo = SetTempos[i + 1];
		}
	}
	return setTempo;
}

TimeSignature^ NoteParser::GetTimeSignature(UInt64 MIDITime) {
	bool isNotFound = true;
	TimeSignature^ timeSignature;
	if (TimeSignatures->Count == 1) {
		timeSignature = TimeSignatures[0];
	}
	else {
		for (int i = 0; (i < (TimeSignatures->Count - 1) && isNotFound); i++) {
			if (TimeSignatures[i]->StartTick <= MIDITime && MIDITime < TimeSignatures[i + 1]->StartTick) {
				timeSignature = TimeSignatures[i];
				isNotFound = false;
			}
			else
				timeSignature = TimeSignatures[i + 1];
		}
	}
	return timeSignature;
}

void NoteParser::SetNoteParams(NormalNote^ note, UInt64 MIDITime) {
	note->setTempo = GetSetTempo(MIDITime);
	note->timeSignature = GetTimeSignature(MIDITime);
}

void NoteParser::Convert() {
	array<double>^ q = gcnew array<double>(1000);
	int k = 0;
	for (int i = 0; i < midiParser->Tracks->Count; i++) {
		MIDITrack^ midiTrack = midiParser->Tracks[i];
		if (midiTrack->GetMIDIEvents()->Count > 0) {
			int currentPosition = 0;
			NoteLine^ noteLine = gcnew NoteLine();
			List<MIDIEvent^>^ midiEvents = midiTrack->GetMIDIEvents();
			int currentMIDITime = midiEvents[0]->MIDITime;
			for (int j = 0; j < midiEvents->Count; j++) {
				if (midiEvents[j]->Status == MIDIStatus::NOTE_ON) {
					NormalNote^ note = gcnew NormalNote();
					note->Height = midiEvents[j]->FirstParam;
					note->Velocity = midiEvents[j]->SecondParam;

					if (midiEvents[j]->MIDITime != currentMIDITime) {
						currentPosition++;
						currentMIDITime = midiEvents[j]->MIDITime;
					}
					note->TrackPosition = currentPosition;
					SetNoteParams(note, midiEvents[j]->MIDITime);
					note->MIDITime = midiEvents[j]->MIDITime;
					
					UInt64 startTime = midiEvents[j]->MIDITime;
					UInt64 nextTime = FindNoteOff(note->Height, midiEvents, j)->MIDITime;
					double difference = nextTime - startTime;
					double partOfQuart = double(TimeDivision / difference);
					double part = double(1 / (4 * partOfQuart));
					note->Length = part;
					noteLine->Notes->Add(note);
					q[k] = note->Length;
					k++;
				}
			}
			if (noteLine->Notes->Count > 0)
				NoteLines->Add(noteLine);
		}
	}

	if (NoteLines->Count > 2)
		throw "Error with NoteLineCount!";
}

UInt16 NoteParser::GetTimeDivision() {
	return TimeDivision;
}