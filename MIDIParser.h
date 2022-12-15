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
	int CurrentStreamPosition;
	int StreamLength;
	int TrackNumber;
	MIDIParserStatus CurrentStatus;
	array<Byte>^ MIDIStream;

	int CurrentChannel;
	UInt64 CurrentTick;
	Byte BufferedChannel;
	MIDIStatus BufferedStatus;
	MIDIHeader^ HeaderData;
	array<MIDITrack^>^ Tracks;

	void ReadMIDIFile(String^ fileName);
	void Parse();
	MIDIParserStatus ParseMeta();
	MIDIParserStatus ParseMIDI();
	MIDIParserStatus ParseSysex();
	MIDIParserStatus ParseHeader();
	MIDIParserStatus ParseTrack();
	MIDIParserStatus ParseEvent();
	MIDIParserStatus ParseChannelEvent();
	bool ParseTime();
	UInt16 Read16Bits();
	UInt32 Read32Bits();
	List<Byte>^ ReadBytes(int count);
	UInt64 ParseVariableLength(int^ length);

	int GetTrackIndex();
};
