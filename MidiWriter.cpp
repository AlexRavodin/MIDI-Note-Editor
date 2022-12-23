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
}

List<Byte>^ Int16ToBytes(UInt16 data) {
	List<Byte>^ bytes = gcnew List<Byte>();
	bytes->Add((data >> 8) & 0xFF);
	bytes->Add(data & 0xFF);
}

List<Byte>^ VariableToBytes(UInt64 value) {

}

List<Byte>^ GetNoteOn(UInt64) {

}

List<Byte>^ GetHeader(int numberOfTracks, UInt16 PPQcount) {
	List<Byte>^ nameBytes = gcnew List<Byte>();
	String^ MIDI_HEADER = "MThd";
	for (int i = 0; i < MIDI_HEADER->Length; i++)
		nameBytes->Add(MIDI_HEADER[i]);
	UInt32 length = 6;
	UInt16 fileFormat = 1;
	UInt16 trackNumber = numberOfTracks;
	UInt16 PPQNumber = PPQcount;
	List<Byte>^ headerBytes = gcnew List<Byte>();
	
	headerBytes->AddRange(nameBytes);
	headerBytes->AddRange(Int32ToBytes(length));
	headerBytes->AddRange(Int16ToBytes(fileFormat));
	headerBytes->AddRange(Int16ToBytes(trackNumber));
	headerBytes->AddRange(Int16ToBytes(PPQNumber));

	return headerBytes;
}

List<Byte>^ GetTrack(NoteLine^ noteLine) {
	List<Byte>^ nameBytes = gcnew List<Byte>();
	String^ TRACK_HEADER = "MThd";
	for (int i = 0; i < TRACK_HEADER->Length; i++)
		nameBytes->Add(TRACK_HEADER[i]);
	List<Byte>^ trackBytes = gcnew List<Byte>();

	trackBytes->AddRange(nameBytes);
	UInt32 trackLengthIndex = trackBytes->Count;
	trackBytes->AddRange(Int32ToBytes(trackLengthIndex));



	return trackBytes;
}

void MIDIWriter::GetMIDIStream() {
	List<Byte>^ stream = gcnew List<Byte>();
	MIDIStream->AddRange(GetHeader(CurrentNoteParser->NoteLines->Count, PPQNumber));
	for (int i = 0; i < CurrentNoteParser->NoteLines->Count; i++) {
		MIDIStream->AddRange(GetTrack(CurrentNoteParser->NoteLines[i]));
	}
}

MIDIWriter::MIDIWriter() {
}

MIDIWriter::MIDIWriter(NoteParser^ noteParser, String^ fileName) {
	CurrentNoteParser = noteParser;
	FileStream^ currMIDIStream = gcnew FileStream(fileName, FileMode::Open);
	BinaryWriter^ byteWriter = gcnew BinaryWriter(currMIDIStream);
	MIDIStream = gcnew List<Byte>();

	GetMIDIStream();
	byteWriter->Write(MIDIStream->ToArray());

	byteWriter->Close();
	currMIDIStream->Close();
}