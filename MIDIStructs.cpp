#include "MIDIStructs.h"

MIDITrack::MIDITrack() {

	MIDIMetaEvent^ keySignature = gcnew MIDIMetaEvent();
	keySignature->Type = MIDIMeta::KEY_SIGNATURE;
	keySignature->MidiTime = 0;
	keySignature->ChannelNumber = 0;
	keySignature->Length = 2;
	List<Byte>^ data = gcnew List<Byte>(2);
	data[0] = 0x04;
	data[1] = 0x01;
	keySignature->SetData(data);
	AddMetaEvent(keySignature);

	MIDIMetaEvent^ keySignature = gcnew MIDIMetaEvent();
	keySignature->Type = MIDIMeta::SET_TEMPO;
	keySignature->MidiTime = 0;
	keySignature->ChannelNumber = 0;
	List<Byte>^ data = gcnew List<Byte>(3);
	data[0] = 0x07;
	data[1] = 0xA1;
	data[2] = 0x20;
	keySignature->SetData(data);
	AddMetaEvent(keySignature);

	MIDIMetaEvent^ keySignature = gcnew MIDIMetaEvent();
	keySignature->Type = MIDIMeta::TIME_SIGNATURE;
	keySignature->MidiTime = 0;
	keySignature->ChannelNumber = 0;
	keySignature->Length = 2;
	List<Byte>^ data = gcnew List<Byte>(4);
	data[0] = 0x04;
	data[1] = 0x02;
	data[2] = 0x18;
	data[3] = 0x08;
	keySignature->SetData(data);
	AddMetaEvent(keySignature);


}