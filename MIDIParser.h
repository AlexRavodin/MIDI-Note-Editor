#pragma once

using namespace System;
using namespace System::Windows::Forms;

ref class MIDIParser
{
public:
	MIDIParser();
	MIDIParser(String^ fileName);
	void PrintStreamToBox(TextBox^ textBox);
private:
	array<Byte>^ MIDIStream;
	void ReadMIDIFile(String^ fileName);
};

