#pragma once
#include "MIDIValues.h"

using namespace System;
using namespace System::Drawing;

public enum Directions {
	Up,
	Down
};

ref struct Clef {
	String^ fontName;
	String^ charToPrint;
public:
	Clef() {}
	Clef(String^ fontName, String^ charToPrint) {
		this->fontName = fontName;
		this->charToPrint = charToPrint;
	}
};

ref struct Accidental {
	String^ fontName;
	String^ charToPrint;
public:
	Accidental() {}
	Accidental(String^ fontName, String^ charToPrint) {
		this->fontName = fontName;
		this->charToPrint = charToPrint;
	}
};

ref struct Note {
	String^ fontName;
	String^ upCharToPrint;
	String^ downCharToPrint;
public:
	Note() {}
	Note(String^ fontName, String^ upCharToPrint, String^ downCharToPrint) {
		this->fontName = fontName;
		this->upCharToPrint = upCharToPrint;
		this->downCharToPrint = downCharToPrint;
	}
};

ref  class BMPFactory abstract sealed
{
public:
	static BMPFactory();
	static Bitmap^ GetNote(int duration, Directions direction);
	static Bitmap^ GetSign(Accidentals accidental);
	static Bitmap^ GetPause(int duration);
	static Bitmap^ Get—lef(Clefs clef);
	static Bitmap^ GetMetre(int bars, int beats);
private:
	static Dictionary<int, Note^>^ DurToNote;
	static Dictionary<int, Accidental^>^ NumToAcc;
	static Dictionary<int, Clef^>^ NumToClef;
};
