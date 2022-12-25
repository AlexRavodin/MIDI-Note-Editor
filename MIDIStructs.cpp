#include "MIDIStructs.h"

MIDITrack::MIDITrack() {
	BytesLeft = 0;
	MidiEvents = gcnew List<MIDIEvent^>();
	MetaEvents = gcnew List<MIDIMetaEvent^>();
	SysexEvents = gcnew List<MIDISysexEvent^>();

	MIDIMetaEvent^ keySignature = gcnew MIDIMetaEvent();
	keySignature->Type = MIDIMeta::KEY_SIGNATURE;
	keySignature->MIDITime = 0;
	keySignature->ChannelNumber = 0;
	keySignature->Length = 2;
	List<Byte>^ keyData = gcnew List<Byte>();
	keyData->Add(0x04);
	keyData->Add(0x01);
	keySignature->SetData(keyData);
	AddMetaEvent(keySignature);

	MIDIMetaEvent^ setTempo = gcnew MIDIMetaEvent();
	setTempo->Type = MIDIMeta::SET_TEMPO;
	setTempo->MIDITime = 0;
	setTempo->ChannelNumber = 0;
	List<Byte>^ tempoData = gcnew List<Byte>(3);
	tempoData->Add(0x07);
	tempoData->Add(0xA1);
	tempoData->Add(0x20);
	setTempo->SetData(tempoData);
	AddMetaEvent(setTempo);

	MIDIMetaEvent^ timeSignature = gcnew MIDIMetaEvent();
	timeSignature->Type = MIDIMeta::TIME_SIGNATURE;
	timeSignature->MIDITime = 0;
	timeSignature->ChannelNumber = 0;
	timeSignature->Length = 2;
	List<Byte>^ timeData = gcnew List<Byte>(4);
	timeData->Add(0x04);
	timeData->Add(0x02);
	timeData->Add(0x18);
	timeData->Add(0x08);
	timeSignature->SetData(timeData);
	AddMetaEvent(timeSignature);
}

MIDIMetaEvent::MIDIMetaEvent() {
	Data = gcnew List<Byte>();
}

MIDISysexEvent::MIDISysexEvent() {
	Data = gcnew List<Byte>();
}

NoteLine::NoteLine() {
	Notes = gcnew List<NormalNote^>();
}

NoteOff::NoteOff() {
}

NoteOff::NoteOff(UInt64 MIDITime, Byte velocity, Byte height) {
	Velocity = velocity;
	this->MIDITime = MIDITime;
	Height = height;
}

NotePosition::NotePosition(int tempo, int numerator, int denumerator, int clef, List<int>^ heights, List<int>^ accs) {
	Tempo = tempo;
	Numerator = numerator;
	Denumerator = denumerator;
	Clef = clef;
	Heights = heights;
	Accs = accs;
}