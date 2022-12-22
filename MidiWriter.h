#pragma once
#include "NoteParser.h"
#include "MIDIValues.h";
#include "MIDIStructs.h";

using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class MidiWriter{
public:
	MIDIWriter();
	MIDIWriter(NoteParser^ noteParser);
private:
	NoteParser^ NoteParser;
};

