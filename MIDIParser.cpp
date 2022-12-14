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

UInt32 MIDIParser::Read32Bits() {
    UInt32 Data = (MIDIStream[CurrentStreamPosition] << 24) | (MIDIStream[CurrentStreamPosition] << 16) | (MIDIStream[CurrentStreamPosition] << 8) | MIDIStream[CurrentStreamPosition];
    CurrentStreamPosition += 2;
    return Data;
}

UInt16 MIDIParser::Read16Bits() {
    UInt16 Data = (MIDIStream[CurrentStreamPosition] << 8) | MIDIStream[CurrentStreamPosition + 1];
    CurrentStreamPosition += 2;
    return Data;
}

UInt64 MIDIParser::ParseVariableLength() {
    UInt64 Data = 0;


}

bool MIDIParser::ParseTime() {
    Byte NumberOfBytes = 0;
    Byte ContinueFlag = 1;
    UInt64 NewTime = 0;

    while (ContinueFlag != 0) {
        NumberOfBytes++;

        if (CurrentStreamPosition < nbytes || parser->track.size < nbytes)
            return false;

        uint8_t b = parser->in[nbytes - 1];
        parser->vtime = (parser->vtime << 7) | (b & 0x7f);

        // The largest value allowed within a MIDI file is 0x0FFFFFFF. A lot of
        // leading bytes with the highest bit set might overflow the nbytes counter
        // and create an endless loop.
        // If one would use 0x80 bytes for padding the check on parser->vtime would
        // not terminate the endless loop. Since the maximum value can be encoded
        // in 5 bytes or less, we can assume bad input if more bytes were used.
        if (NewTime > 0x0fffffff || NumberOfBytes > 5)
            return false;

        ContinueFlag = b & 0x80;
    }

    parser->in += nbytes;
    parser->size -= nbytes;
    parser->track.size -= nbytes;

    return true;


}

void MIDIParser::PrintStreamToBox(TextBox^ textBox) {
    String^ streamText;
    streamText = System::Text::Encoding::ASCII->GetString(MIDIParser::MIDIStream);
    textBox->Text = streamText;
}

MIDIParserStatus MIDIParser::ParseTrack() {
    const int MIN_TRACK_LENGTH = 8;
    String^ MIDI_TRACK = "MTrk";

    if (MIDIStream->Length < MIN_TRACK_LENGTH)
        return MIDIParserStatus::ERROR;
    for (int i = 0; i < 4; i++) {
        if (MIDIStream[i] != MIDI_TRACK[i])
            return MIDIParserStatus::ERROR;
    }
    CurrentStreamPosition += 4;

    Tracks[Tracks->Length - 1]->TrackLength = Read32Bits();
    BufferedStatus = MIDIStatus::NO_STATUS;
    CurrentStatus = MIDIParserStatus::TRACK;

    return MIDIParserStatus::TRACK;
}

MIDIParserStatus MIDIParser::ParseHeader() {
    const int HEADER_LENGTH = 14;
    String^ MIDI_HEADER = "MThd";

    if (MIDIStream-> Length < HEADER_LENGTH)
        return MIDIParserStatus::ERROR;
    for (int i = 0; i < 4; i++) {
        if (MIDIStream[i] != MIDI_HEADER[i])
            return MIDIParserStatus::ERROR;
    }
    CurrentStreamPosition += 4;

    HeaderData->HeaderLength = Read32Bits();
    HeaderData->FileFormat = Read16Bits();
    HeaderData->TrackNumber = Read16Bits();
    HeaderData->PPQNumber = Read16Bits();
    CurrentStatus = MIDIParserStatus::HEADER;

    return MIDIParserStatus::HEADER;
}

void MIDIParser::ParseMidi() {
    CurrentStatus = MIDIParserStatus::INIT;

    while (true) {
        if (MIDIStream->Length - CurrentStreamPosition < 1)
            CurrentStatus = MIDIParserStatus::ERROR;
        switch (CurrentStatus)
        {
        case MIDIParserStatus::INIT:
            ParseHeader();
            break;
        case MIDIParserStatus::HEADER:
            break;
        case MIDIParserStatus::TRACK:
            break;
        case MIDIParserStatus::TRACK_MIDI:
            break;
        case MIDIParserStatus::TRACK_META:
            break;
        case MIDIParserStatus::TRACK_SYSEX:
            break;
        default:
            break;
        }
    }
}