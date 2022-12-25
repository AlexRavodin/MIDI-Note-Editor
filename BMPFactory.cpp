#include "BMPFactory.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


BMPFactory::BMPFactory() {
	DurToNote = gcnew Dictionary<double, Note^>();
	DurToNote->Add(0.03125, gcnew Note("MusicalSymbols", "r", "R"));
	DurToNote->Add(0.0625, gcnew Note("MusicalSymbols", "x", "X"));
	DurToNote->Add(0.125, gcnew Note("MusicalSymbols", "e", "E"));
	DurToNote->Add(0.25, gcnew Note("MusicalSymbols", "q", "q"));
	DurToNote->Add(0.5, gcnew Note("MusicalSymbols", "h", "H"));
	DurToNote->Add(1, gcnew Note("MusicalSymbols", "w", "w"));
	DurToNote->Add(2, gcnew Note("MusicalSymbols", "W", "W"));
	NumToAcc = gcnew Dictionary<Accidentals, Accidental^>();
	NumToAcc->Add(Accidentals::Flat, gcnew Accidental("MusicalSymbols", "b"));
	NumToAcc->Add(Accidentals::Sharp, gcnew Accidental("MusicalSymbols", "#"));
	NumToAcc->Add(Accidentals::Natural, gcnew Accidental("MusicalSymbols", "n"));
	NumToClef = gcnew Dictionary<Clefs, Clef^>();
	NumToClef->Add(Clefs::Treble, gcnew Clef("MusicalSymbols", "&"));
	NumToClef->Add(Clefs::Bas, gcnew Clef("MusicalSymbols", "?"));
}

void BMPFactory::GetNote(Bitmap^ bitmap, double duration, Directions direction, int width, int height, int x, int y) {
	RectangleF rectf(x, y, x + width, y + height);
	Graphics^ g = Graphics::FromImage(bitmap);

	Font^ font = gcnew Font(DurToNote[duration]->fontName, 40);

	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;

	g->DrawString(direction == Directions::Up ? DurToNote[duration]->upCharToPrint : DurToNote[duration]->upCharToPrint, font, Brushes::Black, rectf, format);
}

void BMPFactory::GetSign(Bitmap^ bitmap, Accidentals accidental, int width, int height, int x, int y) {
	RectangleF rectf(x, y, x + width, y + height);
	Graphics^ g = Graphics::FromImage(bitmap);

	Font^ font = gcnew Font(NumToAcc[accidental]->fontName, 30);

	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;
	SolidBrush^ b = gcnew SolidBrush(Color::Aqua);

	g->FillRectangle(b, rectf);

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;

	g->DrawString(NumToAcc[accidental]->charToPrint, font, Brushes::Black, rectf, format);
}

void BMPFactory::GetСlef(Bitmap^ bitmap, Clefs clef, int width, int height, int x, int y) {
	RectangleF rectf(x, y, x + width, y + height);
	Graphics^ g = Graphics::FromImage(bitmap);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Aqua);
	
	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;
	Font^ font = gcnew Font(NumToClef[clef]->fontName, 25);

	g->DrawString(NumToClef[clef]->charToPrint, font, Brushes::Black, rectf, format);
	//g->Graphics::FillRectangle(solidBrush, rectf);
	//g->Flush();
}


void BMPFactory::GetRest(Duration duration) {

	
}

void BMPFactory::GetMetre(int bars, int beats) {

	
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

void BMPFactory::DrawPosition(PictureBox^ notesPictureBox, int centerVerticalLineOffset, int positionWidth, int x, NotePosition^ notePosition) {
	int offset = 0;
	/*
	Bitmap^ notesBitmap = gcnew Bitmap(notesPictureBox->Width, notesPictureBox->Height);
	Graphics^ g = Graphics::FromImage(notesPictureBox->Image);

	if (notePosition->Clef != nullptr) {
		GetСlef(notesBitmap, notePosition->Clef, );
		offset += positionWidth;
	}
	if (notePosition->Numerator != 0) {
		g->DrawString(NumToClef[clef]->charToPrint, font, Brushes::Black, rectf, format);
		offset += positionWidth;
	}
	if (notePosition->Te)
	RectangleF rectf(0, 0, notesBitmap->Width, notesBitmap->Height);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Aqua);

	Pen^ linePen = gcnew Pen(Color::Black);
	Graphics^ notesCanvas = Graphics::FromImage(notesBitmap);
	notesCanvas->Graphics::FillRectangle(solidBrush, rectf);
	//int currentVerticalLinesOffset = centerVerticalLineOffset - 4 * HalfLineWidth;

	notesCanvas->Flush();
	notesPictureBox->Image = notesBitmap;
	*/
}