#pragma once

#include "MIDIValues.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

ref struct MIDIMetaEvent {
public:
	property int ChannelNumber;

	property int Length;
	property UInt64 MidiTime;
	property MIDIMeta Type;

	void SetData(List<Byte>^ data) {
		Data = data;
	}
private:
	List<Byte>^ Data;
};

ref struct MIDINote {
public:
	property int ChannelNumber;

	property UInt64 StartTime;
	property UInt64 EndTime;
	property UInt64 MidiTime;

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
	property UInt64 MidiTime;

	property int TrackPosition;

	property Byte FirstParam;
	property Byte SecondParam;
};

ref struct MIDISysexEvent {
public:
	property int TrackPosition;
	property int ChannelNumber;
	property int Length;
	void Add(List<Byte>^ data) {
		Data->AddRange(data);
	}
	void RemoveLast() {
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
	property UInt32 TrackLength;
	property UInt32 CurrentPosition;
	void AddNote(MIDINote^ note) {
		Notes->Add(note);
	}
	void AddMetaEvent(MIDIMetaEvent^ event) {
		MetaEvents->Add(event);
	}
	void AddSysexEvent(MIDISysexEvent^ event) {
		SysexEvents->Add(event);
	}
private:
	List<MIDINote^>^ Notes;
	List<MIDINote^>^ NormalizedNotes;
	List<MIDIMetaEvent^>^ MetaEvents;
	List<MIDISysexEvent^>^ SysexEvents;
};