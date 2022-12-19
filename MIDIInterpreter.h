#pragma once
#include "MIDIStructs.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

ref class MIDIInterpreter{
public:
	static void PrintEvent(MIDIEvent^ midiEvent, StreamWriter^ logWriter);
	static void PrintEvent(MIDIMetaEvent^ metaEvent, StreamWriter^ logWriter);
	static void PrintEvent(MIDISysexEvent^ sysexEvent, StreamWriter^ logWriter);
	static void PrintHeader(MIDIHeader^ midiHeader, StreamWriter^ logWriter);
	static void PrintTrack(MIDITrack^ midiTrack, StreamWriter^ logWriter);
	static void PrintError(String^ errorText, StreamWriter^ logWriter);
	static void PrintLengthError(StreamWriter^ logWriter);
};