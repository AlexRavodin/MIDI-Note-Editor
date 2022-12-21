#pragma once
#include "MIDIParser.h"
#include "MIDIStructs.h"

ref class NoteParser{
public:
	NoteParser();
	NoteParser(MIDIParser^ midiParser);
	void GetTimeSignature(MIDIParser^ midiParser);
	void GetSetTempos(MIDIParser^ midiParser);
	void Convert();
private:
	int NoteLineCount;
	List<UInt16>^ MinHeights;
	List<UInt16>^ MaxHeights;
	int Numerator;
	int Denumerator;
	UInt16 TimeDivision;
	
	MIDIParser^ midiParser;
	List<NoteLine^>^ NoteLines;
	List<SetTempo^>^ SetTempos;
};
