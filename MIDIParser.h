#pragma once
#include "MIDIStructs.h"
#include "MIDIValues.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

ref class MIDIParser {
public:
	MIDIParser();
	MIDIParser(String^ fileName);
	void PrintStreamToBox(TextBox^ textBox);
private:
	int BytesLeft;
	int CurrentStreamPosition;
	int StreamLength;
	MIDIParserStatus CurrentStatus;
	array<Byte>^ MIDIStream;

	int CurrentChannel;
	Byte BufferedChannel;
	MIDIStatus BufferedStatus;
	MIDIHeader^ HeaderData;
	List<MIDITrack^>^ Tracks;

	void ReadMIDIFile(String^ fileName);

	UInt16 Read16Bits();
	UInt32 Read32Bits();
	List<Byte>^ ReadBytes(int count);
	UInt64 ParseVariableLength(List<Byte>^ data);

	void Parse();
	bool ParseTime(UInt64^ time);
	MIDIParserStatus ParseMeta();
	MIDIParserStatus ParseMIDI();
	MIDIParserStatus ParseSysex();
	MIDIParserStatus ParseHeader();
	MIDIParserStatus ParseTrack();
	MIDIParserStatus ParseEvent();

	void MoveFullPosition(int offset);

	MIDITrack^ GetCurrentTrack();
};
