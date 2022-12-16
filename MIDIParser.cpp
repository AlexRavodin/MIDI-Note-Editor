#include "MIDIParser.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

int GetMIDIEventDataLength(MIDIStatus status) {
    switch (status) {
        case MIDIStatus::PROGRAM_CHANGE: return 1;
        case MIDIStatus::CHANNEL_AT: return 1;
        default: return 2;
    }
}

MIDIParser::MIDIParser() {
}

MIDIParser::MIDIParser(String^ fileName) {
    ReadMIDIFile(fileName);
    TrackNumber = 0;
    StreamLength = 0;
    BytesLeft = 0;
}

void MIDIParser::ReadMIDIFile(String^ fileName) {
    try
    {
        FileStream^ currMIDIStream = gcnew FileStream(fileName, FileMode::Open);

        BinaryReader^ byteReader = gcnew BinaryReader(currMIDIStream);

        Array::Resize(MIDIStream, currMIDIStream->Length);
        StreamLength = currMIDIStream->Length;
        BytesLeft = StreamLength;
        byteReader->Read(MIDIStream, 0, currMIDIStream->Length);

        byteReader->Close();
        currMIDIStream->Close();
    }
    catch (Exception^ e)
    {
        MIDIStream = nullptr;
    }
}

UInt16 MIDIParser::Read16Bits() {
    UInt16 Data = (MIDIStream[CurrentStreamPosition] << 8) | MIDIStream[CurrentStreamPosition + 1];
    CurrentStreamPosition += 2;
    BytesLeft -= 2;
    return Data;
}

UInt32 MIDIParser::Read32Bits() {
    UInt32 Data = (MIDIStream[CurrentStreamPosition] << 24) | (MIDIStream[CurrentStreamPosition + 1] << 16) | (MIDIStream[CurrentStreamPosition + 2] << 8) | MIDIStream[CurrentStreamPosition + 3];
    CurrentStreamPosition += 4;
    BytesLeft -= 2;
    return Data;
}

List<Byte>^ MIDIParser::ReadBytes(int count) {
    List<Byte>^ data;
    for (int i = CurrentStreamPosition; i < CurrentStreamPosition + count; i++)
        data->Add(MIDIStream[i]);
    return data;
}

UInt64 MIDIParser::ParseVariableLength(UInt32^ offset) {
    UInt64 value = 0;
    UInt32  i = *offset;
    for (; i < MIDIStream->Length; i++) {
        value = (value << 7) | (MIDIStream[i] & 0x7f);
        if (!(MIDIStream[i] & 0x80))
            break;
    }
    *offset = i + 1;
    return value;
}

bool MIDIParser::ParseTime() {
    Byte numberOfBytes = 0;
    Byte continueFlag = 1;
    Byte nextByte = 0;
    UInt64 newTime = 0;

    while (continueFlag != 0) {
        numberOfBytes++;

        if ((StreamLength - CurrentStreamPosition - 1 < numberOfBytes) || 
           (Tracks[GetTrackIndex()]->TrackLength - Tracks[GetTrackIndex()]->CurrentPosition - 1 < numberOfBytes))
            return false;

        nextByte = MIDIStream[CurrentStreamPosition + numberOfBytes - 1];
        newTime = (newTime << 7) | (nextByte & 0x7f);

        if (newTime > 0x0fffffff || numberOfBytes > 5)
            return false;

        continueFlag = nextByte & 0x80;
    }

    CurrentStreamPosition += numberOfBytes;
    Tracks[GetTrackIndex()]->CurrentPosition += numberOfBytes;

    return true;
}

MIDIParserStatus MIDIParser::ParseMeta() {
    if (BytesLeft < 2)
        return MIDIParserStatus::ERROR;

    MIDIMetaEvent^ midiMeta = gcnew MIDIMetaEvent();
    midiMeta->Type = (MIDIMeta)MIDIStream[CurrentStreamPosition + 1];
    UInt32^ offset = gcnew UInt32(2);
    midiMeta->Length = ParseVariableLength(offset);
    midiMeta->SetData(ReadBytes(midiMeta->Length));

    CurrentStreamPosition += *offset;
    Tracks[GetTrackIndex()]->CurrentPosition += *offset;
    BytesLeft -= *offset;

    return MIDIParserStatus::TRACK_META;
}

MIDIParserStatus MIDIParser::ParseSysex()
{
    //assert(parser->size == 0 || parser->in[0] == 0xf0);

    if (StreamLength - CurrentStreamPosition < 2)
        return MIDIParserStatus::ERROR;

    MIDISysexEvent^ sysexEvent = gcnew MIDISysexEvent();
    sysexEvent->TrackPosition = CurrentStreamPosition;
                
    UInt32^ offset = gcnew UInt32(1);
    sysexEvent->Length = ParseVariableLength(offset);
    if (*offset < 1 || *offset > StreamLength - CurrentStreamPosition - 1)
        return MIDIParserStatus::ERROR;

    CurrentStreamPosition += *offset;
    Tracks[GetTrackIndex()]->CurrentPosition += *offset;
    
    if (sysexEvent->Length <= 0 || sysexEvent->Length > MIDIStream->Length)
        return MIDIParserStatus::ERROR;
    
    sysexEvent->Add(ReadBytes(sysexEvent->Length));
    CurrentStreamPosition += sysexEvent->Length;
    Tracks[GetTrackIndex()]->CurrentPosition += sysexEvent->Length;
    
    if (sysexEvent->GetByIndex(sysexEvent->Length - 1) == 0xF7)
    {
        sysexEvent->RemoveLast();

    }

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

    Tracks[GetTrackIndex()]->TrackLength = Read32Bits();
    BufferedStatus = MIDIStatus::NO_STATUS;
    CurrentStatus = MIDIParserStatus::TRACK;

    return MIDIParserStatus::TRACK;
}

MIDIParserStatus MIDIParser::ParseHeader() {
    const int HEADER_LENGTH = 14;
    String^ MIDI_HEADER = "MThd";

    if (BytesLeft < HEADER_LENGTH)
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

MIDIParserStatus MIDIParser::ParseMIDI() {
    if (MIDIStream->Length - CurrentStreamPosition < 2)
       return MIDIParserStatus::ERROR;

    MIDIEvent^ midiEvent = gcnew MIDIEvent();

    if ((MIDIStream[CurrentStreamPosition] & 0x80) == 0) {
        if (BufferedStatus == MIDIStatus::NO_STATUS)
            return MIDIParserStatus::ERROR;

        midiEvent->Status = BufferedStatus;
        int dataLength = GetMIDIEventDataLength(midiEvent->Status);
        if (MIDIStream->Length - CurrentStreamPosition < dataLength)
            return MIDIParserStatus::ERROR;

        midiEvent->ChannelNumber = BufferedChannel;
        midiEvent->FirstParam = (dataLength > 0 ? MIDIStream[CurrentStreamPosition] : 0);
        midiEvent->SecondParam = (dataLength > 1 ? MIDIStream[CurrentStreamPosition + 1] : 0);

        CurrentStreamPosition += dataLength;
        Tracks[GetTrackIndex()]->CurrentPosition += dataLength;
    }
    else {
        if (MIDIStream->Length - CurrentStreamPosition < 3)
            return MIDIParserStatus::ERROR;

        midiEvent->Status = (MIDIStatus)((MIDIStream[CurrentStreamPosition] >> 4) & 0xf);
        int dataLength = GetMIDIEventDataLength(midiEvent->Status);
        if (MIDIStream->Length - CurrentStreamPosition < dataLength + 1)
            return MIDIParserStatus::ERROR;

        midiEvent->ChannelNumber = MIDIStream[CurrentStreamPosition] & 0xf;
        midiEvent->FirstParam = (dataLength > 0 ? MIDIStream[CurrentStreamPosition + 1] : 0);
        midiEvent->SecondParam = (dataLength > 1 ? MIDIStream[CurrentStreamPosition + 2] : 0);
        BufferedStatus = midiEvent->Status;
        BufferedChannel = midiEvent->ChannelNumber;

        CurrentStreamPosition += dataLength + 1;
        Tracks[GetTrackIndex()]->CurrentPosition += dataLength + 1;
    }
    return MIDIParserStatus::TRACK_MIDI;
}

MIDIParserStatus MIDIParser::ParseEvent() {
    if (ParseTime() == false)
        return MIDIParserStatus::ERROR;

    //if (parser->size <= 0 || parser->track.size <= 0)
    //    return MIDIParserStatus::ERROR;

    if (MIDIStream[CurrentStreamPosition] < 0xf0) {
        return ParseMIDI();
    }
    else {  
        BufferedStatus = MIDIStatus::NO_STATUS;  
        if (MIDIStream[CurrentStreamPosition] == 0xf0)
            return ParseSysex();
        if (MIDIStream[CurrentStreamPosition] == 0xff)
            return ParseMeta();
    }
    return MIDIParserStatus::ERROR;
}

void MIDIParser::Parse() {
    CurrentStatus = MIDIParserStatus::INIT;
    bool isNotEnd = false;

    while (CurrentStatus != MIDIParserStatus::ERROR && isNotEnd) {
        if ((MIDIStream->Length - CurrentStreamPosition < 1) ||
            (MIDIStream->Length < 1))
            CurrentStatus = MIDIParserStatus::ERROR;
        switch (CurrentStatus)
        {
        case MIDIParserStatus::INIT:
            ParseHeader();
            break;
        case MIDIParserStatus::HEADER:
            ParseTrack();
            break;
        case MIDIParserStatus::TRACK:
            if (Tracks[GetTrackIndex()]->TrackLength -
                Tracks[GetTrackIndex()]->CurrentPosition == 1) {
                CurrentStatus = MIDIParserStatus::HEADER;
            }
            else
                ParseEvent();
            break;
        default:
            MIDIParserStatus::ERROR;
            break;
        }
    }
}

int MIDIParser::GetTrackIndex() {
    return (Tracks->Length - 1);
}