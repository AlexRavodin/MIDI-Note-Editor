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
	MaxHeights = gcnew List<UInt16>();
	MinHeights = gcnew List<UInt16>();
	int Numerator = 4;
	int Denumerator = 4;
	UInt16 TimeDivision = 120;
	NoteLines = gcnew List<NoteLine^>();
	SetTempos = gcnew List<SetTempo^>();
	Convert();
}

void NoteParser::GetTimeSignature(MIDIParser^ midiParser) {
	for (int i = 0; i < midiParser->Tracks->Count; i++) {
		MIDITrack^ midiTrack = midiParser->Tracks[i];
		List<MIDIMetaEvent^>^ metaEvents = midiTrack->GetMetaEvents();
		for (int j = 0; j < metaEvents->Count; j++) {
			if (metaEvents[j]->Type == MIDIMeta::TIME_SIGNATURE) {
				Numerator = (int)metaEvents[j]->GetData()[0];
				Denumerator = (int)metaEvents[j]->GetData()[1];
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
				setTempo->BPM = ConvertBytesToNumber(metaEvents[j]->GetData());
				SetTempos->Add(setTempo);
			}
		}
	}
}

void NoteParser::Convert() {	
	for (int i = 0; i < midiParser->Tracks->Count; i++) {
		MIDITrack^ midiTrack = midiParser->Tracks[i];
		if (midiTrack->GetMIDIEvents()->Count > 0) {
			int currentPosition = 0;
			NoteLine^ noteLine = gcnew NoteLine();
			List<MIDIEvent^>^ midiEvents = midiTrack->GetMIDIEvents();
			for (int j = 0; j < midiEvents->Count; j++) {
				if (midiEvents[j]->Status == MIDIStatus::NOTE_ON) {
					NormalNote^ note = gcnew NormalNote();
					note->Height = midiEvents[j]->FirstParam;
					note->Velocity = midiEvents[j]->SecondParam;
					note->TrackPosition = currentPosition++;
					UInt64 div = midiParser->GetTimeDivision();
					UInt64 start = midiEvents[j]->MIDITime;
					UInt64 next = FindNoteOff(note->Height, midiEvents, j)->MIDITime;
					UInt64 dif = next - start;
					note->Length = (midiParser->GetTimeDivision() / (FindNoteOff(note->Height, midiEvents, j)->MIDITime - midiEvents[j]->MIDITime));
					//
					noteLine->Notes->Add(note);
				}
			}
			if (noteLine->Notes->Count > 0)
				NoteLines->Add(noteLine);
		}
	}
	if (NoteLines->Count > 2)
		throw "GG NoteLineCOunt";
}