#pragma once
#include "MIDIParser.h"
#include "MIDIStructs.h"

ref class NoteParser{
public:
	NoteParser();
	NoteParser(MIDIParser^ midiParser);
	void GetTimeSignatures(MIDIParser^ midiParser);
	void GetSetTempos(MIDIParser^ midiParser);
	void Convert();
	void SetNoteParams(NormalNote^ note, UInt64 MIDITime);
	List<NoteLine^>^ NoteLines;
private:
	SetTempo^ GetSetTempo(UInt64 MIDITime);
	TimeSignature^ GetTimeSignature(UInt64 MIDITime);

	int NoteLineCount;
	UInt16 TimeDivision;
	
	MIDIParser^ midiParser;

	List<SetTempo^>^ SetTempos;
	List<TimeSignature^>^ TimeSignatures;
};