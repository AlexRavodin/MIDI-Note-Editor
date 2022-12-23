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
	UInt16 GetTimeDivision();
	List<MIDITrack^>^ Tracks;
private:
	UInt64 BytesLeft;
	UInt64 CurrentStreamPosition;
	UInt64 StreamLength;
	MIDIParserStatus CurrentStatus;
	array<Byte>^ MIDIStream;

	property UInt64 MIDITime;
	int CurrentChannel;
	bool GotEndOfTrackEvent;
	Byte BufferedChannel;
	MIDIStatus BufferedStatus;
	MIDIHeader^ HeaderData;

	void ReadMIDIFile(String^ fileName);

	UInt16 Read16Bits();
	UInt32 Read32Bits();
	List<Byte>^ ReadBytes(int count);
	UInt64 ParseVariableLength(List<Byte>^ data);

	void Parse();
	bool ParseTime(UInt64^ time);
	MIDIParserStatus ParseMeta(StreamWriter^ logWriter);
	MIDIParserStatus ParseMIDI(StreamWriter^ logWriter);
	MIDIParserStatus ParseSysex(StreamWriter^ logWriter);
	MIDIParserStatus ParseHeader(StreamWriter^ logWriter);
	MIDIParserStatus ParseTrack(StreamWriter^ logWriter);
	MIDIParserStatus ParseEvent(StreamWriter^ logWriter);

	void MoveFullPosition(int offset);

	MIDITrack^ GetCurrentTrack();
};
