#pragma once
#include "MIDIValues.h"
#include "MIDIStructs.h"

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

ref class BMPFactory abstract sealed{
public:
	static BMPFactory();
	static void GetNote(Bitmap^ bitmap, double duration, Directions direction, int width, int height, int x, int y, int fontSize);
	static void GetRest(Duration duration);
	static void GetSign(Bitmap^ bitmap, Accidentals accidental, int width, int height, int x, int y, int fontSize);
	static void Get—lef(Bitmap^ bitmap, Clefs clef, int width, int height, int x, int y, int fontSize);
	static void GetMetre(Bitmap^ bitmap, int num, int denum, int width, int height, int x, int y, int fontSize);
	static void GetExtraLines(Bitmap^ bitmap, int top, int bottom, int width, int x, int centerVerticalLineOffset, int halfLineWidth);
	static void DrawLines(PictureBox^ notesPictureBox, int centerVerticalLineOffset, int lineLength, int halfLineWidth);
	static void DrawPosition(PictureBox^ notesPictureBox, int centerVerticalLineOffset, int positionWidth, int halfLineWidth, int x, NotePosition^ notePosition, int index, bool drawPos);
	static void BMPFactory::DrawNumber(Bitmap^ bitmap, String^ str, int width, int height, int x, int y, int fontSize);
private:
	static Dictionary<double, Note^>^ DurToNote;
	static Dictionary<Duration, Note^>^ DurToPause;
	static Dictionary<Accidentals, Accidental^>^ NumToAcc;
	static Dictionary<Clefs, Clef^>^ NumToClef;
};
