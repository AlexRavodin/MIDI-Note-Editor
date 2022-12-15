#include "MIDIStructs.h"

MIDITrack::MIDITrack() {

	MIDIMetaEvent^ keySignature = gcnew MIDIMetaEvent();
	keySignature->Type = MIDIMeta::KEY_SIGNATURE;
	keySignature->MidiTime = 0;
	keySignature->ChannelNumber = 0;
	keySignature->Length = 2;
	List<Byte>^ keyData = gcnew List<Byte>(2);
	keyData[0] = 0x04;
	keyData[1] = 0x01;
	keySignature->SetData(keyData);
	AddMetaEvent(keySignature);

	MIDIMetaEvent^ setTempo = gcnew MIDIMetaEvent();
	setTempo->Type = MIDIMeta::SET_TEMPO;
	setTempo->MidiTime = 0;
	setTempo->ChannelNumber = 0;
	List<Byte>^ tempoData = gcnew List<Byte>(3);
	tempoData[0] = 0x07;
	tempoData[1] = 0xA1;
	tempoData[2] = 0x20;
	setTempo->SetData(tempoData);
	AddMetaEvent(setTempo);

	MIDIMetaEvent^ timeSignature = gcnew MIDIMetaEvent();
	timeSignature->Type = MIDIMeta::TIME_SIGNATURE;
	timeSignature->MidiTime = 0;
	timeSignature->ChannelNumber = 0;
	timeSignature->Length = 2;
	List<Byte>^ timeData = gcnew List<Byte>(4);
	timeData[0] = 0x04;
	timeData[1] = 0x02;
	timeData[2] = 0x18;
	timeData[3] = 0x08;
	timeSignature->SetData(timeData);
	AddMetaEvent(timeSignature);


}