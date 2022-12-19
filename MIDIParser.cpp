#include "MIDIParser.h"
#include "MIDIInterpreter.h"

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
    MIDITime = 0;
    StreamLength = 0;
    BytesLeft = 0;
    GotEndOfTrackEvent = false;
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
    List<Byte>^ data = gcnew List<Byte>();
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
    MoveFullPosition(i + 1 - CurrentStreamPosition);
    return value;
}

MIDIParserStatus MIDIParser::ParseHeader(StreamWriter^ logWriter) {
    const int HEADER_LENGTH = 14;
    String^ MIDI_HEADER = "MThd";

    if (BytesLeft < HEADER_LENGTH){
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }
    for (int i = 0; i < 4; i++) {
        if (MIDIStream[i] != MIDI_HEADER[i]) {
            MIDIInterpreter::PrintError("Wrong header name.", logWriter);
            return MIDIParserStatus::ERROR;
        }
    }
    CurrentStreamPosition += 4;
    BytesLeft -= 4;

    HeaderData->HeaderLength = Read32Bits();
    HeaderData->FileFormat = Read16Bits();
    HeaderData->TrackNumber = Read16Bits();
    HeaderData->PPQNumber = Read16Bits();
    MIDIInterpreter::PrintHeader(HeaderData, logWriter);
    return MIDIParserStatus::HEADER;
}

MIDIParserStatus MIDIParser::ParseTrack(StreamWriter^ logWriter) {
    GotEndOfTrackEvent = false;
    MIDITime = 0;
    const int MIN_TRACK_LENGTH = 8;
    String^ MIDI_TRACK = "MTrk";

    if (BytesLeft < MIN_TRACK_LENGTH)
    {
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }

    MIDITrack^ midiTrack = gcnew MIDITrack();
    midiTrack->Number = Tracks->Count;
    Tracks->Add(midiTrack);
    for (int i = 0; i < 4; i++) {
        if (MIDIStream[CurrentStreamPosition + i] != MIDI_TRACK[i]) {
            MIDIInterpreter::PrintError("Wrong track name.", logWriter);
            return MIDIParserStatus::ERROR;
        }
    }
    MoveFullPosition(4);

    GetCurrentTrack()->TrackLength = Read32Bits();
    GetCurrentTrack()->BytesLeft = GetCurrentTrack()->TrackLength;
    GetCurrentTrack()->CurrentPosition = 0;
    BufferedStatus = MIDIStatus::NO_STATUS;

    MIDIInterpreter::PrintTrack(midiTrack, logWriter);
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

MIDIParserStatus MIDIParser::ParseMeta(StreamWriter^ logWriter) {
    if (BytesLeft < 3) {
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }

    MIDIMetaEvent^ metaEvent = gcnew MIDIMetaEvent();
    metaEvent->Type = (MIDIMeta)MIDIStream[CurrentStreamPosition + 1];
    metaEvent->MIDITime = MIDITime;
    if (metaEvent->Type == MIDIMeta::END_OF_TRACK) {
        GotEndOfTrackEvent = true;
    }
    MoveFullPosition(2);
    List<Byte>^ data = gcnew List<Byte>();
    metaEvent->Length = ParseVariableLength(data);

    if (metaEvent->Length < 0 || BytesLeft < metaEvent->Length || GetCurrentTrack()->BytesLeft < metaEvent->Length) {
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }

    metaEvent->SetData(ReadBytes(metaEvent->Length));

    GetCurrentTrack()->AddMetaEvent(metaEvent);
    MIDIInterpreter::PrintEvent(metaEvent, logWriter);

    return MIDIParserStatus::TRACK;
}

MIDIParserStatus MIDIParser::ParseSysex(StreamWriter^ logWriter)
{
    if (BytesLeft < 2 || GetCurrentTrack()->BytesLeft < 2) {
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }

    MIDISysexEvent^ sysexEvent = gcnew MIDISysexEvent();
    sysexEvent->MIDITime = MIDITime;
    sysexEvent->Manufactor = MIDIStream[CurrentStreamPosition + 1];
    MoveFullPosition(2);
    List<Byte>^ data = gcnew List<Byte>();
    sysexEvent->Length = ParseVariableLength(data);
    if (sysexEvent->Length < 1 || BytesLeft < sysexEvent->Length || GetCurrentTrack()->BytesLeft < sysexEvent->Length) {
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }
    
    sysexEvent->Add(ReadBytes(sysexEvent->Length));
    sysexEvent->RemoveLast();
    GetCurrentTrack()->AddSysexEvent(sysexEvent);
    MIDIInterpreter::PrintEvent(sysexEvent, logWriter);

    return MIDIParserStatus::TRACK;
}

MIDIParserStatus MIDIParser::ParseMIDI(StreamWriter^ logWriter) {
    if (MIDIStream->Length - CurrentStreamPosition < 2) {
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }

    MIDIEvent^ midiEvent = gcnew MIDIEvent();
    midiEvent->MIDITime = MIDITime;

    if ((MIDIStream[CurrentStreamPosition] & 0x80) == 0) {
        if (BufferedStatus == MIDIStatus::NO_STATUS) {
            MIDIInterpreter::PrintError("No buffered status when required.", logWriter);
            return MIDIParserStatus::ERROR;
        }

        midiEvent->Status = BufferedStatus;
        int dataLength = GetMIDIEventDataLength(midiEvent->Status);
        if (BytesLeft < dataLength || GetCurrentTrack()->BytesLeft < dataLength) {
            MIDIInterpreter::PrintLengthError(logWriter);
            return MIDIParserStatus::ERROR;
        }

        midiEvent->ChannelNumber = BufferedChannel;
        midiEvent->FirstParam = (dataLength > 0 ? MIDIStream[CurrentStreamPosition] : 0);
        midiEvent->SecondParam = (dataLength > 1 ? MIDIStream[CurrentStreamPosition + 1] : 0);

        MoveFullPosition(dataLength);
    }
    else {
        midiEvent->Status = (MIDIStatus)((MIDIStream[CurrentStreamPosition] >> 4) & 0xf);
        int dataLength = GetMIDIEventDataLength(midiEvent->Status);
        if (BytesLeft < dataLength + 1 || GetCurrentTrack()->BytesLeft < dataLength + 1) {
            MIDIInterpreter::PrintLengthError(logWriter);
            return MIDIParserStatus::ERROR;
        }

        midiEvent->ChannelNumber = MIDIStream[CurrentStreamPosition] & 0xf;
        midiEvent->FirstParam = (dataLength > 0 ? MIDIStream[CurrentStreamPosition + 1] : 0);
        midiEvent->SecondParam = (dataLength > 1 ? MIDIStream[CurrentStreamPosition + 2] : 0);
        BufferedStatus = midiEvent->Status;
        BufferedChannel = midiEvent->ChannelNumber;

        MoveFullPosition(dataLength + 1);
    }

    GetCurrentTrack()->AddMidiEvent(midiEvent);
    MIDIInterpreter::PrintEvent(midiEvent, logWriter);

    return MIDIParserStatus::TRACK;
}

MIDIParserStatus MIDIParser::ParseEvent(StreamWriter^ logWriter) {
    UInt64^ time = gcnew UInt64(0);
    if (ParseTime(time) == false)
    {
        MIDIInterpreter::PrintError("Time parsing error.", logWriter);
        return MIDIParserStatus::ERROR;
    }
    MIDITime += *time;

    if (BytesLeft < 1 || GetCurrentTrack()->BytesLeft < 1) {
        MIDIInterpreter::PrintLengthError(logWriter);
        return MIDIParserStatus::ERROR;
    }

    if (MIDIStream[CurrentStreamPosition] < 0xf0) {
        return ParseMIDI(logWriter);
    }
    else {  
        BufferedStatus = MIDIStatus::NO_STATUS;
        if (MIDIStream[CurrentStreamPosition] == 0xf0)
            return ParseSysex(logWriter);
        if (MIDIStream[CurrentStreamPosition] == 0xff)
            return ParseMeta(logWriter);
    }
    MIDIInterpreter::PrintError("Unknown status.", logWriter);
    return MIDIParserStatus::ERROR;
}

void MIDIParser::Parse() {
    CurrentStatus = MIDIParserStatus::INIT;
    bool isNotEnd = true;

    String^ logFilePath = Directory::GetCurrentDirectory() + "\\" + "logs.txt";
    StreamWriter^ logWriter = gcnew StreamWriter(logFilePath);

    while (CurrentStatus != MIDIParserStatus::ERROR && isNotEnd) {
        switch (CurrentStatus){
        case MIDIParserStatus::INIT:
            CurrentStatus = ParseHeader(logWriter);
            break;
        case MIDIParserStatus::HEADER:
            if (BytesLeft == 0)
                isNotEnd = false;
            else{
                CurrentStatus = ParseTrack(logWriter);
            }
            break;
        case MIDIParserStatus::TRACK:
            if (GetCurrentTrack()->BytesLeft != 0) {
                CurrentStatus = ParseEvent(logWriter);
            }
            else if (GotEndOfTrackEvent)
                CurrentStatus = MIDIParserStatus::HEADER;
            else{
                MIDIInterpreter::PrintError("No end of track meta event.", logWriter);
                CurrentStatus = MIDIParserStatus::ERROR;
            }
            break;
        default:
            CurrentStatus = MIDIParserStatus::ERROR;
            break;
        }
    }
    logWriter->Close();
}

MIDITrack^ MIDIParser::GetCurrentTrack() {
    return Tracks[Tracks->Count - 1];
}