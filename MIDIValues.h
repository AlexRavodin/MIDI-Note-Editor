#pragma once

using namespace System::Collections::Generic;

public enum MIDIParserStatus{
	EOB = -2,
	ERROR = -1,
	INIT = 0,
	HEADER = 1,
	TRACK = 2,
	TRACK_MIDI = 3,
	TRACK_META = 4,
	TRACK_SYSEX = 5,
};

public enum MIDIFileFormat{
	SINGLE_TRACK = 0,
	MULTIPLE_TRACKS = 1,
	MULTIPLE_SONGS = 2,
};

public enum MIDIStatus{
	NOTE_OFF = 0x8,
	NOTE_ON = 0x9,
	NOTE_AT = 0xA,
	CONTROL_CHANGE = 0xB,
	PROGRAM_CHANGE = 0xC,
	CHANNEL_AT = 0xD,
	PITCH_BEND = 0xE,
};

public enum MIDIMeta{
	SEQ_NUM = 0x00,
	TEXT = 0x01,
	COPYRIGHT = 0x02,
	TRACK_NAME = 0x03,
	INSTRUMENT_NAME = 0x04,
	LYRICS = 0x05,
	MAKER = 0x06,
	CUE_POINT = 0x07,
	CHANNEL_PREFIX = 0x20,
	END_OF_TRACK = 0x2F,
	SET_TEMPO = 0x51,
	SMPTE_OFFSET = 0x54,
	TIME_SIGNATURE = 0x58,
	KEY_SIGNATURE = 0x59,
	SEQ_SPECIFIC = 0x7F,
};

public enum Clefs {
	Treble,
	Bas
};

public enum Accidentals {
	Flat,
	Natural,
	Sharp
};

public enum MIDINotes
{
	Cm1 = 0, //-1 oct
	Cdies,
	D,
	Ddies,	
	E,
	F,
	Fdies,	
	G,
	Gdies,
	A,
	Adies,
	B,
	C0,
	Cdies0,	
	D0,
	Ddies0,	
	E0,
	F0,
	Fdies0,
	G0,
	Gdies0,
	A0,
	Adies0,
	B0,
	C1,
	Cdies1,
	D1,
	Ddies1,
	E1,
	F1,
	Fdies1,
	G1,
	Gdies1,
	A1,
	Adies1,
	B1,
	C2,
	Cdies2,
	D2,
	Ddies2,
	E2,
	F2,
	Fdies2,
	G2,
	Gdies2,
	A2,
	Adies2,
	B2,
	C3,
	Cdies3,
	D3,
	Ddies3,
	E3,
	F3,
	Fdies3,
	G3,
	Gdies3,
	A3,
	Adies3,
	B3,
	C4, //middle C
	Cdies4,
	D4,
	Ddies4,
	E4,
	F4,
	Fdies4,
	G4,
	Gdies4,
	A4, //concert pitchbend
	Adies4,
	B4,
	C5,
	Cdies5,
	D5,
	Ddies5,
	E5,
	F5,
	Fdies5,
	G5,
	Gdies5,
	A5,
	Adies5,
	B5,
	C6,
	Cdies6,
	D6,
	Ddies6,
	E6,
	F6,
	Fdies6,
	G6,
	Gdies6,
	A6,
	Adies6,
	B6,
	C7,
	Cdies7,
	D7,
	Ddies7,
	E7,
	F7,
	Fdies7,
	G7,
	Gdies7,
	A7,
	Adies7,
	B7,
	C8,
	Cdies8,
	D8,
	Ddies8,
	E8,
	F8,
	Fdies8,
	G8,
	Gdies8,
	A8,
	Adies8,
	B8,
	C9,
	Cdies9,
	D9,
	Ddies9,
	E9,
	F9,
	Fdies9,
	G9
};