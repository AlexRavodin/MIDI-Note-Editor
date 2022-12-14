#pragma once
#include "MIDIValues.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

ref class MIDIParser{
public:
	MIDIParser();
	MIDIParser(String^ fileName);
	void PrintStreamToBox(TextBox^ textBox);
private:
	int CurrentStreamPosition;
	MIDIParserStatus CurrentStatus;
	array<Byte>^ MIDIStream;

	int CurrentChannel;
	UInt64 CurrentTick;
	MIDIStatus BufferedStatus;
	MIDIHeader^ HeaderData;
	array<MIDITrack^>^ Tracks;

	void ReadMIDIFile(String^ fileName);
	void ParseMidi();
	MIDIParserStatus ParseHeader();
	MIDIParserStatus ParseTrack();
	bool ParseTime();
	UInt64 ParseVariableLength();
	UInt32 Read32Bits();
	UInt16 Read16Bits();
};

ref struct MIDIMetaEvent{
public:
	UInt64 MidiTime;
	int ChannelNumber = 0;
	MIDIMeta Type;
	array<Byte>^ Data;
};

ref struct MidiNote{
public:
	UInt64 MidiTime;
	int TrackPosition;
	MIDINotes Note;
	Duration Duration;
};

ref struct MIDISysexEvent{
public:
	UInt64 MidiTime;
	int ChannelNumber = 0;
	MIDIMeta Type;
	array<Byte>^ Data;
};

ref struct MIDIHeader {
public:
	UInt32 HeaderLength;
	UInt16 FileFormat;
	UInt16 TrackNumber;
	UInt16 PPQNumber;
};

ref struct MIDITrack {
public:
	UInt32 TrackLength;
	UInt32 CurrentPosition;
	array<MidiNote^>^ Notes;
	array<MIDIMetaEvent^>^ MetaEvents;
};
