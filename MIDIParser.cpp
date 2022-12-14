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
    UInt64 value = 0;
    UInt32  i = CurrentStreamPosition;

    for (; i < MIDIStream->Length; i++) {
        value = (value << 7) | (MIDIStream[i][i] & 0x7f);
        if (!(MIDIStream[i] & 0x80))
            break;
    }
    CurrentStreamPosition = i + 1;
    return value;
}

bool MIDIParser::ParseTime() {
    Byte numberOfBytes = 0;
    Byte continueFlag = 1;
    Byte nextByte = 0;
    UInt64 newTime = 0;

    while (continueFlag != 0) {
        numberOfBytes++;

        if ((MIDIStream->Length - CurrentStreamPosition < numberOfBytes) || 
           (Tracks[Tracks->Length - 1]->TrackLength - Tracks[Tracks->Length - 1]->CurrentPosition < numberOfBytes))
            return false;

        nextByte = MIDIStream[CurrentStreamPosition + numberOfBytes - 1];
        newTime = (newTime << 7) | (nextByte & 0x7f);

        if (newTime > 0x0fffffff || numberOfBytes > 5)
            return false;

        continueFlag = nextByte & 0x80;
    }

    CurrentStreamPosition += numberOfBytes;
    Tracks[Tracks->Length - 1]->CurrentPosition += numberOfBytes;

    return true;
}

MIDIParserStatus MIDIParser::ParseSysex()
{
    assert(parser->size == 0 || parser->in[0] == 0xf0);

    if (parser < 2)
        return MIDI_PARSER_ERROR;

    int offset = 1;
    parser->sysex.length = midi_parse_variable_length(parser, &offset);
    if (offset < 1 || offset > parser->size)
        return MIDI_PARSER_ERROR;
    parser->in += offset;
    parser->size -= offset;
    parser->track.size -= offset;

    // Length should be positive and not more than the remaining size
    if (parser->sysex.length <= 0 || parser->sysex.length > parser->size)
        return MIDI_PARSER_ERROR;

    parser->sysex.bytes = parser->in;
    parser->in += parser->sysex.length;
    parser->size -= parser->sysex.length;
    parser->track.size -= parser->sysex.length;
    // Don't count the 0xF7 ending byte as data, if given:
    if (parser->sysex.bytes[parser->sysex.length - 1] == 0xF7)
        parser->sysex.length--;

    return MIDIParserStatus::TRACK_SYSEX;
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