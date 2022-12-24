#pragma once
#include "NoteParser.h"
#include "MIDIValues.h";
#include "MIDIStructs.h";

using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class MIDIWriter{
public:
	MIDIWriter();
	MIDIWriter(NoteParser^ noteParser, String^ fileName);
	property UInt16 PPQNumber;
private:
	UInt64 CurrentTrackPosition;
	UInt64 CurrentMIDITime;
	UInt64 CurrentDeltaTime;
	UInt16 TimeDivision;

	void GetMIDIStream();
	void CheckSettings(NormalNote^ note, List<Byte>^ bytes, UInt64^ CurrentMIDITime);
	List<Byte>^ GetNotes(NoteLine^ noteLine);
	List<Byte>^ GetTrack(NoteLine^ noteLine);
	UInt64 GetDeltaTime(double noteLength);
	void MIDIWriter::WriteNotesOff(List<NoteOff^>^ notesToOff, List<Byte>^ bytes, UInt64^ ticksAfterLast);

	NoteParser^ CurrentNoteParser;
	List<Byte>^ MIDIStream;
	SetTempo^ CurrentSetTempo;
	TimeSignature^ CurrentTimeSignature;
};

