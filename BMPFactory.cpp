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
	DurToNote->Add(0.25, gcnew Note("MusicalSymbols", "q", "Q"));
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

double GetVerticalOffset(double lineIndex, int centralLineVerticalOffset, int halfLineWidth, Directions currDir) {
	//int extraY = -6 * halfLineWidth;
	double indexDiff = lineIndex - 1;
	double res = centralLineVerticalOffset - (halfLineWidth * 1 * indexDiff) + 0;
	return res;
}

Directions GetDirection(double lineIndex) {
	if (lineIndex > 1)
		return Directions::Down;
	else
		return Directions::Up;
}

void BMPFactory::GetNote(Bitmap^ bitmap, double duration, Directions direction, int width, int height, int x, int y, int fontSize) {
	RectangleF rectf(x, y, x + width, y + height);
	Graphics^ g = Graphics::FromImage(bitmap);

	Font^ font = gcnew Font(DurToNote[duration]->fontName, fontSize);

	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;

	Pen^ pen = gcnew Pen(Color::Black);
	pen->Width = 1;
	//g->DrawEllipse(pen, x, y, 2, 2);
	int radius = 2;
	g->DrawEllipse(pen, x - radius, y - radius,
			radius + radius, radius + radius);

	if (direction == Directions::Up)
		g->DrawString(DurToNote[duration]->upCharToPrint, font, Brushes::Black, rectf, format);
	else
		g->DrawString(DurToNote[duration]->downCharToPrint, font, Brushes::Black, rectf, format);
	g->Flush();
}

void BMPFactory::GetSign(Bitmap^ bitmap, Accidentals accidental, int width, int height, int x, int y, int fontSize) {
	RectangleF rectf(x, y, x + width, y + height);
	Graphics^ g = Graphics::FromImage(bitmap);

	Font^ font = gcnew Font(NumToAcc[accidental]->fontName, fontSize);

	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;
	SolidBrush^ b = gcnew SolidBrush(Color::Aqua);

	//g->FillRectangle(b, rectf);

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;

	g->DrawString(NumToAcc[accidental]->charToPrint, font, Brushes::Black, rectf, format);
}

void BMPFactory::GetСlef(Bitmap^ bitmap, Clefs clef, int width, int height, int x, int y, int fontSize) {
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
	Font^ font = gcnew Font(NumToClef[clef]->fontName, fontSize);

	g->DrawString(NumToClef[clef]->charToPrint, font, Brushes::Black, rectf, format);
	//g->Graphics::FillRectangle(solidBrush, rectf);
	//g->Flush();
}


void BMPFactory::GetRest(Duration duration) {

	
}

void BMPFactory::GetMetre(Bitmap^ bitmap, int num, int denum, int width, int height, int x, int y, int fontSize) {
	RectangleF rectf1(x, y, x + width, y + height / 2);
	RectangleF rectf2(x, y + height / 2, x + width, y + height);
	Graphics^ g = Graphics::FromImage(bitmap);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Aqua);

	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;

	Font^ font = gcnew Font("Times New Roman", fontSize, FontStyle::Bold);

	g->DrawString(num.ToString(), font, Brushes::Black, rectf1, format);
	g->DrawString(denum.ToString(), font, Brushes::Black, rectf2, format);
	g->Flush();
}

void BMPFactory::GetExtraLines(Bitmap^ bitmap, int top, int bottom, int width, int x, int centerVerticalLineOffset, int halfLineWidth) {
	Graphics^ g = Graphics::FromImage(bitmap);



	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;
	int lineLength = width; 
	Pen^ linePen = gcnew Pen(Color::Black);
	linePen->Width = 2;

	int currYOffset = centerVerticalLineOffset;

	for (int i = 0; i < top; i++, currYOffset += 2 * halfLineWidth)
		g->DrawLine(linePen, x, currYOffset, x + lineLength, currYOffset);
	currYOffset = centerVerticalLineOffset + halfLineWidth * 4;
	for (int i = 0; i < bottom; i++, currYOffset -= 2 * halfLineWidth)
		g->DrawLine(linePen, x, currYOffset, x + lineLength, currYOffset);
}

void BMPFactory::DrawLines(PictureBox^ notesPictureBox, int centerVerticalLineOffset, int lineLength, int halfLineWidth) {
	Bitmap^ notesBitmap = gcnew Bitmap(notesPictureBox->Width, notesPictureBox->Height);

	RectangleF rectf(0, 0, notesBitmap->Width, notesBitmap->Height);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Aqua);

	Pen^ linePen = gcnew Pen(Color::Black);
	linePen->Width = 2;

	Graphics^ notesCanvas = Graphics::FromImage(notesBitmap);
	//notesCanvas->Graphics::FillRectangle(solidBrush, rectf);
	int currentVerticalLinesOffset = centerVerticalLineOffset - 6 * halfLineWidth;
	
	for (int i = 0; i < 5; i++, currentVerticalLinesOffset += 2 * halfLineWidth) {
		notesCanvas->DrawLine(linePen, 0, currentVerticalLinesOffset, lineLength, currentVerticalLinesOffset);
	}
	notesCanvas->Flush();
	notesPictureBox->Image = notesBitmap;
}

void BMPFactory::DrawNumber(Bitmap^ bitmap, String^ str, int width, int height, int x, int y, int fontSize) {
	RectangleF rectf1(x, y, x + width, y + height);
	Graphics^ g = Graphics::FromImage(bitmap);

	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;
	g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAliasGridFit;

	StringFormat^ format = gcnew StringFormat();
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;

	Font^ font = gcnew Font("Times New Roman", fontSize, FontStyle::Bold);

	g->DrawString(str, font, Brushes::Black, rectf1, format);
	g->Flush();
}


void BMPFactory::DrawPosition(PictureBox^ notesPictureBox, int centerVerticalLineOffset, 
					int positionWidth, int halfLineWidth, int x, NotePosition^ notePosition, int index, bool drawPos) {
	int offset = 0;
	
	Bitmap^ notesBitmap = gcnew Bitmap(notesPictureBox->Image);

	if (notePosition->ClefChanged) {
		GetСlef(notesBitmap, notePosition->Clef->Clef, positionWidth, halfLineWidth * 7, x + offset, centerVerticalLineOffset - halfLineWidth * 6, 35);
		if (notePosition->Clef->ToneIndex != 0)
			DrawNumber(notesBitmap, "8", 10, 10, x + offset * 0.95, centerVerticalLineOffset - halfLineWidth, 15);
		offset += positionWidth / 2;
	}
	if (notePosition->MetreChanged) {
		GetMetre(notesBitmap, notePosition->Numerator, notePosition->Denumerator, positionWidth, halfLineWidth * 5.5, x + offset, centerVerticalLineOffset - halfLineWidth * 6.6, 30);
		offset += positionWidth;
	}
	if (notePosition->TempoChanged) {
		if (offset == 0) {
			//GetСlef(notesBitmap, notePosition->Clef->Clef, positionWidth, halfLineWidth * 2, x + offset, centerVerticalLineOffset);
			//offset += positionWidth;
		}
		else {
			//offset += positionWidth;
		}
	}

	GetExtraLines(notesBitmap, notePosition->TopExtraLines, notePosition->BottomExtraLines, positionWidth / 2, x + offset + positionWidth * 1.2, centerVerticalLineOffset, halfLineWidth);
	for (int i = 0; i < notePosition->Positions->Count; i++) {
		PositionToDraw^ currPos = notePosition->Positions[i];
		//GetSign(notesBitmap, currPos->position);
		Directions currDir = GetDirection(currPos->lineNumber);
		double yOffset = GetVerticalOffset(currPos->lineNumber, centerVerticalLineOffset, halfLineWidth, currDir);
		GetNote(notesBitmap, currPos->length, currDir, 9, 60, x + offset, yOffset - 40, 30);
		if (drawPos)
			DrawNumber(notesBitmap, index.ToString(), 10, 10, x + offset * 0.95, centerVerticalLineOffset - 8 * halfLineWidth, 15);
	}
	
	notesPictureBox->Image = notesBitmap;
}