#pragma once
#include "MIDIValues.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public enum class Directions {
	Up,
	Down,
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

ref class BMPFactory abstract sealed
{
public:
	static BMPFactory();
	static Bitmap^ GetNote(Duration duration, Directions direction);
	static Bitmap^ GetRest(Duration duration);
	static Bitmap^ GetSign(Accidentals accidental);
	static Bitmap^ Get—lef(Clefs clef);
	static Bitmap^ GetMetre(int bars, int beats);
	static void DrawLines(PictureBox^ notesPictureBox, int verticalLinesOffset);
private:
	static Dictionary<Duration, Note^>^ DurToNote;
	static Dictionary<Duration, Note^>^ DurToPause;
	static Dictionary<Accidentals, Accidental^>^ NumToAcc;
	static Dictionary<Clefs, Clef^>^ NumToClef;
	static int HalfLineWidth = 5;
	static int LineLength = 600;
	static int StartPosition = 40;
};
