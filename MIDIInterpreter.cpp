#include "MIDIInterpreter.h"
#include "MIDIValues.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

String^ InterpreteMIDIStatus(MIDIStatus status){
	switch (status) {
	case MIDIStatus::NOTE_OFF: return "Note Off";
	case MIDIStatus::NOTE_ON: return "Note On";
	case MIDIStatus::NOTE_AT: return "Note Aftertouch";
	case MIDIStatus::CONTROL_CHANGE: return "CC";
	case MIDIStatus::PROGRAM_CHANGE: return "Program Change";
	case MIDIStatus::CHANNEL_AT: return "Channel Aftertouch";
	case MIDIStatus::PITCH_BEND: return "Pitch Bend";
	default: return "(unknown status";
	}
}


String^ InterpreteMetaType(MIDIMeta type){
	switch (type) {
	case MIDIMeta::SEQ_NUM: return "Sequence Number";
	case MIDIMeta::TEXT: return "Text";
	case MIDIMeta::COPYRIGHT: return "Copyright";
	case MIDIMeta::TRACK_NAME: return "Track Name";
	case MIDIMeta::INSTRUMENT_NAME: return "Instrument Name";
	case MIDIMeta::LYRICS: return "Lyrics";
	case MIDIMeta::MAKER: return "Maker";
	case MIDIMeta::CUE_POINT: return "Cue Point";
	case MIDIMeta::CHANNEL_PREFIX: return "Channel Prefix";
	case MIDIMeta::END_OF_TRACK: return "End of Track";
	case MIDIMeta::SET_TEMPO: return "Set Tempo";
	case MIDIMeta::SMPTE_OFFSET: return "SMPTE Offset";
	case MIDIMeta::TIME_SIGNATURE: return "Time Signature";
	case MIDIMeta::KEY_SIGNATURE: return "Key Signature";
	case MIDIMeta::SEQ_SPECIFIC: return "Sequencer Specific";
	default: return "(unknown type)";
	}
}

void MIDIInterpreter::PrintEvent(MIDIEvent^ midiEvent, StreamWriter^ logWriter) {
	logWriter->WriteLine("MIDI event.");
	logWriter->WriteLine("Tick: " + midiEvent->MIDITime);
	logWriter->WriteLine("Channel number: " + midiEvent->ChannelNumber);
	logWriter->WriteLine("Status: " + InterpreteMIDIStatus(midiEvent->Status));
	logWriter->WriteLine("First param: " + midiEvent->FirstParam);
	logWriter->WriteLine("Second param: " + midiEvent->SecondParam);
}

void MIDIInterpreter::PrintEvent(MIDIMetaEvent^ metaEvent, StreamWriter^ logWriter) {
	logWriter->WriteLine("Meta event.");
	logWriter->WriteLine("Tick: " + metaEvent->MIDITime);
	logWriter->WriteLine("Type: " + InterpreteMetaType(metaEvent->Type));
	logWriter->WriteLine("Length: " + metaEvent->Length);
}

void MIDIInterpreter::PrintEvent(MIDISysexEvent^ sysexEvent, StreamWriter^ logWriter) {
	logWriter->WriteLine("Sysex event.");
	logWriter->WriteLine("Length: " + sysexEvent->Length);
}

void MIDIInterpreter::PrintHeader(MIDIHeader^ midiHeader, StreamWriter^ logWriter) {
	logWriter->WriteLine("Header.");
	logWriter->WriteLine("Size: " + midiHeader->HeaderLength);
	logWriter->WriteLine("Track count: " + midiHeader->TrackNumber);
	logWriter->WriteLine("Time division: " + midiHeader->PPQNumber);
}

void MIDIInterpreter::PrintTrack(MIDITrack^ midiTrack, StreamWriter^ logWriter) {
	logWriter->WriteLine("Track.");
	logWriter->WriteLine("Number: " + midiTrack->Number);
	logWriter->WriteLine("Size: " + midiTrack->TrackLength);
}

void MIDIInterpreter::PrintError(String^ errorText, StreamWriter^ logWriter) {
	logWriter->WriteLine(errorText);
}

void MIDIInterpreter::PrintLengthError(StreamWriter^ logWriter) {
	logWriter->WriteLine("Actual length is less than required.");
}