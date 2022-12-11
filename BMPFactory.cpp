#include "BMPFactory.h"

using namespace System::Diagnostics;
using namespace System;
using namespace System::Drawing;
using namespace System::Text;


BMPFactory::BMPFactory() {
	DurToNote = gcnew Dictionary<int, Note^>();
	DurToNote->Add(0, gcnew Note("MusicalSymbols", "W", "W"));
	DurToNote->Add(32, gcnew Note("MusicalSymbols", "r", "R"));
	DurToNote->Add(16, gcnew Note("MusicalSymbols", "x", "X"));
	DurToNote->Add(8, gcnew Note("MusicalSymbols", "e", "E"));
	DurToNote->Add(4, gcnew Note("MusicalSymbols", "q", "q"));
	DurToNote->Add(2, gcnew Note("MusicalSymbols", "h", "H"));
	DurToNote->Add(1, gcnew Note("MusicalSymbols", "w", "w"));
	NumToAcc = gcnew Dictionary<int, Accidental^>();
	NumToAcc->Add((int)Accidentals::Flat, gcnew Accidental("MusicalSymbols", "b"));
	NumToAcc->Add((int)Accidentals::Sharp, gcnew Accidental("MusicalSymbols", "#"));
	NumToAcc->Add((int)Accidentals::Natural, gcnew Accidental("MusicalSymbols", "n"));
	NumToClef = gcnew Dictionary<int, Clef^>();
	NumToClef->Add((int)Clefs::Treble, gcnew Clef("MusicalSymbols", "&"));
	NumToClef->Add((int)Clefs::Bas, gcnew Clef("MusicalSymbols", "?"));
}

Bitmap^ BMPFactory::GetNote(int duration, Directions direction) {;
	Bitmap^ sign = gcnew Bitmap(200, 200);
	Graphics^ g = Graphics::FromImage(sign);
	Font^ font = gcnew Font(DurToNote[duration]->fontName, 300);
	Pen^ blackPen = gcnew Pen(Color::Black, 20);
	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;
	g->DrawString(direction == Directions::Up ? DurToNote[duration]->upCharToPrint : DurToNote[duration]->upCharToPrint, font, Brushes::Black, 100, 100, format);
	//g->Flush();
	return sign;
}


Bitmap^ BMPFactory::GetSign(Accidentals accidental) {
	char CHAR = '\u266F';
	Bitmap^ sign = gcnew Bitmap(1000, 1000);
	RectangleF^ rectf = gcnew RectangleF(0, 0, sign->Width, sign->Height);
	Graphics^ g = Graphics::FromImage(sign);
	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;
	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;
	Font^ font = gcnew Font(NumToAcc[(int)accidental]->fontName, 40);
	Pen^ blackPen = gcnew Pen(Color::Black, 3);
	g->DrawString(NumToAcc[(int)accidental]->charToPrint, font, Brushes::Black, 40, 40, format);

	g->Flush();
	return sign;
}


Bitmap^ BMPFactory::GetPause(int duration) {

	return nullptr;
}

Bitmap^ BMPFactory::GetСlef(Clefs clef) {

	return nullptr;
}

Bitmap^ BMPFactory::GetMetre(int bars, int beats) {

	return nullptr;
}