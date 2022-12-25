#include "BMPFactory.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


BMPFactory::BMPFactory() {
	DurToNote = gcnew Dictionary<Duration, Note^>();
	DurToNote->Add(Duration::Double, gcnew Note("MusicalSymbols", "W", "W"));
	DurToNote->Add(Duration::ThirtySecond, gcnew Note("MusicalSymbols", "r", "R"));
	DurToNote->Add(Duration::Sixteenth, gcnew Note("MusicalSymbols", "x", "X"));
	DurToNote->Add(Duration::Eight, gcnew Note("MusicalSymbols", "e", "E"));
	DurToNote->Add(Duration::Quarter, gcnew Note("MusicalSymbols", "q", "q"));
	DurToNote->Add(Duration::Half, gcnew Note("MusicalSymbols", "h", "H"));
	DurToNote->Add(Duration::Whole, gcnew Note("MusicalSymbols", "w", "w"));
	NumToAcc = gcnew Dictionary<Accidentals, Accidental^>();
	NumToAcc->Add(Accidentals::Flat, gcnew Accidental("MusicalSymbols", "b"));
	NumToAcc->Add(Accidentals::Sharp, gcnew Accidental("MusicalSymbols", "#"));
	NumToAcc->Add(Accidentals::Natural, gcnew Accidental("MusicalSymbols", "n"));
	NumToClef = gcnew Dictionary<Clefs, Clef^>();
	NumToClef->Add(Clefs::Treble, gcnew Clef("MusicalSymbols", "&"));
	NumToClef->Add(Clefs::Bas, gcnew Clef("MusicalSymbols", "?"));
}

Bitmap^ BMPFactory::GetNote(Duration duration, Directions direction) {
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
	Font^ font = gcnew Font(NumToAcc[accidental]->fontName, 40);
	Pen^ blackPen = gcnew Pen(Color::Black, 3);
	g->DrawString(NumToAcc[accidental]->charToPrint, font, Brushes::Black, 40, 40, format);

	g->Flush();
	return sign;
}

Bitmap^ BMPFactory::GetСlef(Clefs clef) {
	Bitmap^ sign = gcnew Bitmap(50, 80);
	RectangleF rectf(0, 0, sign->Width, sign->Height);
	Graphics^ g = Graphics::FromImage(sign);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Aqua);
	
	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;
	Font^ font = gcnew Font(NumToClef[clef]->fontName, 25);
	Pen^ blackPen = gcnew Pen(Color::Black, 3);

	g->DrawString(NumToClef[clef]->charToPrint, font, Brushes::Black, rectf, format);
	g->Graphics::FillRectangle(solidBrush, rectf);
	g->Flush();
	return sign;
}


Bitmap^ BMPFactory::GetRest(Duration duration) {

	return nullptr;
}

Bitmap^ BMPFactory::GetMetre(int bars, int beats) {

	return nullptr;
}

void BMPFactory::DrawLines(PictureBox^ notesPictureBox, int centerVerticalLineOffset, int lineLength, int halfLineWidth) {
	Bitmap^ notesBitmap = gcnew Bitmap(notesPictureBox->Width, notesPictureBox->Height);

	RectangleF rectf(0, 0, notesBitmap->Width, notesBitmap->Height);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Aqua);

	Pen^ linePen = gcnew Pen(Color::Black);
	linePen->Width = 2;

	Graphics^ notesCanvas = Graphics::FromImage(notesBitmap);
	notesCanvas->Graphics::FillRectangle(solidBrush, rectf);
	int currentVerticalLinesOffset = centerVerticalLineOffset - 5 * halfLineWidth;
	for (int i = 0; i < 9; i++, currentVerticalLinesOffset += 2 * halfLineWidth) {
		notesCanvas->DrawLine(linePen, 0, currentVerticalLinesOffset, lineLength, currentVerticalLinesOffset);
	}
	notesCanvas->Flush();
	notesPictureBox->Image = notesBitmap;
}

void BMPFactory::DrawPosition(PictureBox^ notesPictureBox, int centerVerticalLineOffset, int x, int y, NotePosition^ notePosition) {
	Bitmap^ notesBitmap = gcnew Bitmap(notesPictureBox->Width, notesPictureBox->Height);

	RectangleF rectf(0, 0, notesBitmap->Width, notesBitmap->Height);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Aqua);

	Pen^ linePen = gcnew Pen(Color::Black);
	Graphics^ notesCanvas = Graphics::FromImage(notesBitmap);
	notesCanvas->Graphics::FillRectangle(solidBrush, rectf);
	//int currentVerticalLinesOffset = centerVerticalLineOffset - 4 * HalfLineWidth;

	notesCanvas->Flush();
	notesPictureBox->Image = notesBitmap;
}