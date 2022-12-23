#pragma once

#include "MIDIValues.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

ref struct MIDIMetaEvent {
public:
	MIDIMetaEvent();
	property int ChannelNumber;

	property int Length;
	property UInt64 MIDITime;
	property MIDIMeta Type;

	void SetData(List<Byte>^ data) {
		Data = data;
	}
	List<Byte>^ GetData() {
		return Data;
	}
private:
	List<Byte>^ Data;
};

ref struct MIDINote {
public:
	property int ChannelNumber;

	property UInt64 StartTime;
	property UInt64 EndTime;
	property UInt64 MIDITime;

	property int TrackPosition;
	property MIDINotes Note;
	property Byte Velocity;
};

ref struct MIDIEvent {
public:
	property int ChannelNumber;
	property MIDIStatus Status;

	property UInt64 StartTime;
	property UInt64 EndTime;
	property UInt64 MIDITime;

	property int TrackPosition;

	property Byte FirstParam;
	property Byte SecondParam;
};

ref struct MIDISysexEvent {
public:
	MIDISysexEvent();
	property UInt64 MIDITime;
	property int TrackPosition;
	property int ChannelNumber;
	property int Length;
	property int Manufactor;
	void Add(List<Byte>^ data) {
		Data->AddRange(data);
	}
	void RemoveLast() {
		if (Data[Data->Count - 1] == 0xF7)
			Data->Remove(Data->Count - 1);
	}
	Byte GetByIndex(int index) {
		return Data[index];
	}
private:
	List<Byte>^ Data;
};

ref struct MIDIHeader {
public:
	property UInt32 HeaderLength;
	property UInt16 FileFormat;
	property UInt16 TrackNumber;
	property UInt16 PPQNumber;
};

ref struct MIDITrack {
public:
	MIDITrack();
	property int Number;
	property UInt32 TrackLength;
	property UInt32 CurrentPosition;
	property UInt32 BytesLeft;
	void AddMidiEvent(MIDIEvent^ event) {
		MidiEvents->Add(event);
	}
	void AddMetaEvent(MIDIMetaEvent^ event) {
		MetaEvents->Add(event);
	}
	void AddSysexEvent(MIDISysexEvent^ event) {
		SysexEvents->Add(event);
	}
	List<MIDIEvent^>^ GetMIDIEvents() {
		return MidiEvents;
	}
	List<MIDIMetaEvent^>^ GetMetaEvents() {
		return MetaEvents;
	}
	List<MIDISysexEvent^>^ GetSysexEvents() {
		return SysexEvents;
	}
private:
	List<MIDIEvent^>^ MidiEvents;
	List<MIDIMetaEvent^>^ MetaEvents;
	List<MIDISysexEvent^>^ SysexEvents;
};

ref struct SetTempo {
public:
	property UInt64 StartTick;
	property int MPQ;
};

ref struct TimeSignature{
public:
	property UInt64 StartTick;
	property int Numerator;
	property int Denumerator;
};

ref struct NormalNote {
public:
	property int TrackPosition;
	property bool IsNote;
	property double Length;
	property UInt16 Height;
	property UInt16 Velocity;
	property UInt64 MIDITime;
	SetTempo^ setTempo;
	TimeSignature^ timeSignature;
};

ref struct NoteLine {
public:
	NoteLine();
	property int CurrentTempo;
	property int Numerator;
	property int Denumerator;
	List<NormalNote^>^ Notes;
};

