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

void MIDIParser::PrintStreamToBox(TextBox^ textBox) {
    String^ streamText;
    streamText = System::Text::Encoding::ASCII->GetString(MIDIParser::MIDIStream);
    textBox->Text = streamText;
}

MIDIParser::MIDIParser() {
}

MIDIParser::MIDIParser(String^ fileName) {
    StreamLength = 0;
    BytesLeft = 0;
    Tracks = gcnew List<MIDITrack^>();
    ReadMIDIFile(fileName);
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
        
        HeaderData = gcnew MIDIHeader();

        Parse();
    }
    catch (Exception^ e)
    {
        MIDIStream = nullptr;
    }
}

void MIDIParser::MoveFullPosition(int offset) {
    CurrentStreamPosition += offset;
    BytesLeft -= offset;
    GetCurrentTrack()->CurrentPosition += offset;
    GetCurrentTrack()->BytesLeft -= offset;
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
    BytesLeft -= 4;
    return Data;
}

List<Byte>^ MIDIParser::ReadBytes(int count) {
    List<Byte>^ data;
    for (int i = CurrentStreamPosition; i < CurrentStreamPosition + count; i++)
        data->Add(MIDIStream[i]);
    MoveFullPosition(count);
    return data;
}

UInt64 MIDIParser::ParseVariableLength(List<Byte>^ data) {
    UInt64 value = 0;
    UInt32  i = CurrentStreamPosition;
    for (; i < MIDIStream->Length; i++) {
        value = (value << 7) | (MIDIStream[i] & 0x7f);
        data->Add(MIDIStream[i] & 0x7f);
        if ((MIDIStream[i] & 0x80) == 0)
            break;
    }
    MoveFullPosition(i - CurrentStreamPosition);
    return value;
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
    BytesLeft -= 4;

    HeaderData->HeaderLength = Read32Bits();
    HeaderData->FileFormat = Read16Bits();
    HeaderData->TrackNumber = Read16Bits();
    HeaderData->PPQNumber = Read16Bits();
    CurrentStatus = MIDIParserStatus::HEADER;

    return MIDIParserStatus::HEADER;
}

MIDIParserStatus MIDIParser::ParseTrack() {
    const int MIN_TRACK_LENGTH = 8;
    String^ MIDI_TRACK = "MTrk";

    if (BytesLeft < MIN_TRACK_LENGTH)
        return MIDIParserStatus::ERROR;


    MIDITrack^ midiTrack = gcnew MIDITrack();
    Tracks->Add(midiTrack);
    for (int i = 0; i < 4; i++) {
        if (MIDIStream[CurrentStreamPosition + i] != MIDI_TRACK[i])
            return MIDIParserStatus::ERROR;
    }
    MoveFullPosition(4);

    GetCurrentTrack()->TrackLength = Read32Bits();
    GetCurrentTrack()->BytesLeft = GetCurrentTrack()->TrackLength;
    GetCurrentTrack()->CurrentPosition = 0;
    BufferedStatus = MIDIStatus::NO_STATUS;
    CurrentStatus = MIDIParserStatus::TRACK;

    return MIDIParserStatus::TRACK;
}

bool MIDIParser::ParseTime(UInt64^ time) {
    Byte numberOfBytes = 0;
    Byte continueFlag = 1;
    Byte nextByte = 0;

    while (continueFlag != 0) {
        numberOfBytes++;

        if ((BytesLeft < numberOfBytes) || (GetCurrentTrack()->BytesLeft < numberOfBytes))
            return false;

        nextByte = MIDIStream[CurrentStreamPosition + numberOfBytes - 1];
        *time = (*time << 7) | (nextByte & 0x7f);

        if (*time > 0x0fffffff || numberOfBytes > 5)
            return false;

        continueFlag = nextByte & 0x80;
    }

    MoveFullPosition(numberOfBytes);
    return true;
}

MIDIParserStatus MIDIParser::ParseMeta() {
    if (BytesLeft < 3)
        return MIDIParserStatus::ERROR;

    MIDIMetaEvent^ midiMeta = gcnew MIDIMetaEvent();
    midiMeta->Type = (MIDIMeta)MIDIStream[CurrentStreamPosition + 1];
    MoveFullPosition(2);
    List<Byte>^ data = gcnew List<Byte>();
    midiMeta->Length = ParseVariableLength(data);

    if (midiMeta->Length < 1 || BytesLeft < midiMeta->Length || GetCurrentTrack()->BytesLeft < midiMeta->Length)
        return MIDIParserStatus::ERROR;

    midiMeta->SetData(ReadBytes(midiMeta->Length));

    return MIDIParserStatus::TRACK_META;
}

MIDIParserStatus MIDIParser::ParseSysex()
{
    if (StreamLength - CurrentStreamPosition < 2)
        return MIDIParserStatus::ERROR;

    MIDISysexEvent^ sysexEvent = gcnew MIDISysexEvent();
    sysexEvent->Manufactor = MIDIStream[CurrentStreamPosition + 1];
    MoveFullPosition(2);
    List<Byte>^ data = gcnew List<Byte>();
    sysexEvent->Length = ParseVariableLength(data);
    if (sysexEvent->Length < 1 || BytesLeft < sysexEvent->Length || GetCurrentTrack()->BytesLeft < sysexEvent->Length)
        return MIDIParserStatus::ERROR;
    
    sysexEvent->Add(ReadBytes(sysexEvent->Length));
    sysexEvent->RemoveLast();

    return MIDIParserStatus::TRACK_SYSEX;
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
        if (BytesLeft < dataLength || GetCurrentTrack()->BytesLeft < dataLength)
            return MIDIParserStatus::ERROR;

        midiEvent->ChannelNumber = BufferedChannel;
        midiEvent->FirstParam = (dataLength > 0 ? MIDIStream[CurrentStreamPosition] : 0);
        midiEvent->SecondParam = (dataLength > 1 ? MIDIStream[CurrentStreamPosition + 1] : 0);

        MoveFullPosition(dataLength);
    }
    else {
        midiEvent->Status = (MIDIStatus)((MIDIStream[CurrentStreamPosition] >> 4) & 0xf);
        int dataLength = GetMIDIEventDataLength(midiEvent->Status);
        if (BytesLeft < dataLength + 1 || GetCurrentTrack()->BytesLeft < dataLength + 1)
            return MIDIParserStatus::ERROR;

        midiEvent->ChannelNumber = MIDIStream[CurrentStreamPosition] & 0xf;
        midiEvent->FirstParam = (dataLength > 0 ? MIDIStream[CurrentStreamPosition + 1] : 0);
        midiEvent->SecondParam = (dataLength > 1 ? MIDIStream[CurrentStreamPosition + 2] : 0);
        BufferedStatus = midiEvent->Status;
        BufferedChannel = midiEvent->ChannelNumber;

        MoveFullPosition(dataLength + 1);
    }

    return MIDIParserStatus::TRACK_MIDI;
}

MIDIParserStatus MIDIParser::ParseEvent() {
    UInt64^ time = gcnew UInt64(0);
    if (ParseTime(time) == false)
        return MIDIParserStatus::ERROR;

    if (BytesLeft < 1 || GetCurrentTrack()->BytesLeft < 1)
        return MIDIParserStatus::ERROR;

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
    while (CurrentStatus != MIDIParserStatus::ERROR && true) {
        switch (CurrentStatus)
        {
        case MIDIParserStatus::INIT:
            ParseHeader();
            break;
        case MIDIParserStatus::HEADER:
            if (BytesLeft == 0)
                isNotEnd = true;
            else
                ParseTrack();
            break;
        case MIDIParserStatus::TRACK:
            if (GetCurrentTrack()->BytesLeft == 0) {
                CurrentStatus = MIDIParserStatus::HEADER;
            }
            else
                ParseEvent();
            break;
        default:
            CurrentStatus = MIDIParserStatus::ERROR;
            break;
        }
    }

    int k = 0;
}

MIDITrack^ MIDIParser::GetCurrentTrack() {
    return Tracks[Tracks->Count - 1];
}