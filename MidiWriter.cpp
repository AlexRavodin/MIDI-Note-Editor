#include "MidiWriter.h"
#include "NoteParser.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

List<Byte>^ Int32ToBytes(UInt32 data) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->Add((data >> 24) & 0xFF);
	bytes->Add((data >> 16) & 0xFF);
	bytes->Add((data >> 8) & 0xFF);
	bytes->Add(data & 0xFF);
	return bytes;
}

List<Byte>^ Int16ToBytes(UInt16 data) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->Add((data >> 8) & 0xFF);
	bytes->Add(data & 0xFF);
	return bytes;
}

List<Byte>^ GetDeltaTimeList(UInt64 deltaTime) {
	List<Byte>^ bytes = gcnew List<Byte>();
	for (int i = 0; i < 3; i++) {
		bytes->Add(80 | deltaTime & 0x7f);
		deltaTime >>= 7;
	}
	bytes->Add((deltaTime & 0x7f));
	return bytes;
}

List<Byte>^ GetNoteOn(UInt64 deltaTime, Byte velocity, Byte height) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->AddRange(GetDeltaTimeList(deltaTime));
	bytes->Add(0x90);
	bytes->Add(height);
	bytes->Add(velocity);
	return bytes;
}

List<Byte>^ GetNoteOff(UInt64 deltaTime, Byte velocity, Byte height) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->AddRange(GetDeltaTimeList(deltaTime));
	bytes->Add(0x80);
	bytes->Add(height);
	bytes->Add(velocity);
	return bytes;
}

List<Byte>^ GetHeader(int numberOfTracks, UInt16 TPQcount) {
	List<Byte>^ nameBytes = gcnew List<Byte>();
	String^ MIDI_HEADER = "MThd";
	for (int i = 0; i < MIDI_HEADER->Length; i++)
		nameBytes->Add(MIDI_HEADER[i]);
	UInt32 length = 6;
	UInt16 fileFormat = 1;
	UInt16 trackNumber = numberOfTracks;
	UInt16 PPQNumber = TPQcount;
	List<Byte>^ headerBytes = gcnew List<Byte>();

	headerBytes->AddRange(nameBytes);
	headerBytes->AddRange(Int32ToBytes(length));
	headerBytes->AddRange(Int16ToBytes(fileFormat));
	headerBytes->AddRange(Int16ToBytes(trackNumber));
	headerBytes->AddRange(Int16ToBytes(PPQNumber));

	return headerBytes;
}

List<Byte>^ GetSetTempo(UInt64 TPQ, UInt64 deltaTime) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->AddRange(GetDeltaTimeList(deltaTime));
	bytes->Add(0xFF);
	bytes->Add(0x51);
	bytes->Add(0x04);
	int shift = 24;
	for (int i = 0; i < 4; i++) {
		bytes->Add((TPQ >> shift) & 0xff);
		shift -= 8;
	}
	return bytes;
}

List<Byte>^ GetTimeSignature(Byte numberator, Byte denumerator, UInt64 deltaTime) {
	Byte denumByte = System::Math::Log(denumerator, 2);
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->AddRange(GetDeltaTimeList(deltaTime));
	bytes->Add(0xFF);
	bytes->Add(0x58);
	bytes->Add(0x04);
	bytes->Add(numberator);
	bytes->Add(denumByte);
	bytes->Add(0x18);
	bytes->Add(0x08);
	return bytes;
}

List<Byte>^ GetProgramChange(UInt64 deltaTime) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->AddRange(GetDeltaTimeList(deltaTime));
	bytes->Add(0xC0); 
	bytes->Add(0x00); 
	return bytes;
}

List<Byte>^ GetEndOfTrackEvent(UInt64 deltaTime) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->AddRange(GetDeltaTimeList(deltaTime));
	bytes->Add(0xff);
	bytes->Add(0x2f);
	bytes->Add(0x00);
	return bytes;
}

void MIDIWriter::CheckSettings(NormalNote^ note, List<Byte>^ bytes, UInt64 deltaTime) {
	if (note->setTempo->TPQ != CurrentSetTempo->TPQ) {
		bytes->AddRange(GetSetTempo(note->setTempo->TPQ, deltaTime));
		CurrentSetTempo = note->setTempo;
	}
	if ((note->timeSignature->Numerator != CurrentTimeSignature->Numerator) || (note->timeSignature->Denumerator != CurrentTimeSignature->Denumerator)){
		bytes->AddRange(GetTimeSignature(note->timeSignature->Numerator, note->timeSignature->Denumerator, deltaTime));
		CurrentTimeSignature = note->timeSignature;
	}
}

UInt64 MIDIWriter::GetDeltaTime(double noteLength) {
	UInt16 timeDivision = TimeDivision;
	UInt64 deltaTime = System::Math::Truncate(double(noteLength / 0.25) * timeDivision);
	return deltaTime;
}

List<NoteOff^>^ GetCurrentNotesOff(List<NoteOff^>^ notesOff, UInt64 midiTIme) {
	List<NoteOff^>^ currentNotesOff = gcnew List<NoteOff^>();
	NoteOff^ currentNoteOff;
	for (int i = 0; i < notesOff->Count; i++) {
		if ((notesOff[i] != nullptr) && (notesOff[i]->MIDITime <= midiTIme)) {
			currentNoteOff = notesOff[i];
			notesOff[i] != nullptr;
		}
	}
	return currentNotesOff;
}

void MIDIWriter::WriteNotesOff(List<NoteOff^>^ notesToOff, List<Byte>^ bytes) {
	if (notesToOff->Count > 0) {
		bytes->AddRange(GetNoteOff(CurrentDeltaTime, notesToOff[0]->Velocity, notesToOff[0]->Height));
		CurrentDeltaTime = 0;
		for (int i = 1; i < notesToOff->Count; i++) {
			bytes->AddRange(GetNoteOff(CurrentDeltaTime, notesToOff[i]->Velocity, notesToOff[i]->Height));
		}
	}
}

List<Byte>^ MIDIWriter::GetNotes(NoteLine^ noteLine) {
	List<Byte>^ bytes = gcnew List<Byte>();
	List<NoteOff^>^ notesOff = gcnew List<NoteOff^>();
	
	List<NormalNote^>^ notes = noteLine->Notes;
	for (int i = 0; i < notes->Count; i++) {
		UInt64 noteDeltaTime = GetDeltaTime(notes[i]->Length);
		NoteOff^ noteOff = gcnew NoteOff(CurrentMIDITime + noteDeltaTime, notes[i]->Velocity, notes[i]->Height);
		notesOff->Add(noteOff);
		if (notes[i]->TrackPosition != CurrentTrackPosition) {
			List<NoteOff^>^ notesToOff = GetCurrentNotesOff(notesOff, CurrentMIDITime);

			CheckSettings(notes[i], bytes, CurrentMIDITime);
			bytes->AddRange(GetNoteOn(CurrentDeltaTime, notes[i]->Velocity, notes[i]->Height));
			CurrentMIDITime += noteDeltaTime;
		}
		else {
			CurrentDeltaTime = 0;
			bytes->AddRange(GetNoteOn(CurrentDeltaTime, notes[i]->Velocity, notes[i]->Height));
		}
	}
	return bytes;
}

List<Byte>^ MIDIWriter::GetTrack(NoteLine^ noteLine) {
	List<Byte>^ nameBytes = gcnew List<Byte>();
	String^ TRACK_HEADER = "MThd";
	for (int i = 0; i < TRACK_HEADER->Length; i++)
		nameBytes->Add(TRACK_HEADER[i]);
	List<Byte>^ trackBytes = gcnew List<Byte>();

	trackBytes->AddRange(nameBytes);
	UInt32 trackLengthIndex = trackBytes->Count;
	trackBytes->AddRange(Int32ToBytes(trackLengthIndex));

	trackBytes->AddRange(GetProgramChange(CurrentDeltaTime));
	trackBytes->AddRange(GetNotes(noteLine));
	trackBytes->AddRange(GetEndOfTrackEvent(CurrentDeltaTime));
	return trackBytes;
}

void MIDIWriter::GetMIDIStream() {
	List<Byte>^ stream = gcnew List<Byte>();
	MIDIStream->AddRange(GetHeader(CurrentNoteParser->NoteLines->Count, TimeDivision));
	for (int i = 0; i < CurrentNoteParser->NoteLines->Count; i++) {
		MIDIStream->AddRange(GetTrack(CurrentNoteParser->NoteLines[i]));
	}
}

MIDIWriter::MIDIWriter() {
}

SetTempo^ GetFirstSetTempo(NoteParser^ noteParser) {
	return noteParser->NoteLines[0]->Notes[0]->setTempo;
}
TimeSignature^ GetFirstTimeSignature(NoteParser^ noteParser) {
	return noteParser->NoteLines[0]->Notes[0]->timeSignature;
}


MIDIWriter::MIDIWriter(NoteParser^ noteParser, String^ fileName) {
	CurrentNoteParser = noteParser;

	CurrentTrackPosition = 0;
	CurrentMIDITime = 0;
	CurrentDeltaTime = 0;
	TimeDivision = noteParser->GetTimeDivision();

	CurrentSetTempo = GetFirstSetTempo(noteParser);
	CurrentTimeSignature = GetFirstTimeSignature(noteParser);

	FileStream^ currMIDIStream = gcnew FileStream(fileName, FileMode::Open);
	BinaryWriter^ byteWriter = gcnew BinaryWriter(currMIDIStream);
	MIDIStream = gcnew List<Byte>();

	GetMIDIStream();
	byteWriter->Write(MIDIStream->ToArray());

	byteWriter->Close();
	currMIDIStream->Close();
}