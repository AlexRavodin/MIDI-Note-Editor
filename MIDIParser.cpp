#include "MIDIParser.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

MIDIParser::MIDIParser() {
}

MIDIParser::MIDIParser(String^ fileName) {
    ReadMIDIFile(fileName);
}

void MIDIParser::ReadMIDIFile(String^ fileName) {
    try
    {
        FileStream^ currMIDIStream = gcnew FileStream(fileName, FileMode::Open);

        BinaryReader^ byteReader = gcnew BinaryReader(currMIDIStream);

        Array::Resize(MIDIStream, currMIDIStream->Length);
        byteReader->Read(MIDIStream, 0, currMIDIStream->Length);

        byteReader->Close();
        currMIDIStream->Close();
    }
    catch (Exception^ e)
    {
        MIDIStream = nullptr;
    }
}

void MIDIParser::PrintStreamToBox(TextBox^ textBox) {
    String^ streamText;
    streamText = System::Text::Encoding::ASCII->GetString(MIDIParser::MIDIStream);
    textBox->Text = streamText;
}