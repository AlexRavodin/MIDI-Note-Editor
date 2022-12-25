#include "EditForm.h"

using namespace MIDINoteEditor;
using namespace System;
using namespace System::Windows::Forms;

void ClearBitmap(Bitmap^ bitmap) {
	Graphics^ g = Graphics::FromImage(bitmap);
	g->Clear(Color::White);
}

System::Void EditForm::EditForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		MIDIParser^ tempMIDIParser = gcnew MIDIParser(this->FileName);
		noteParser = gcnew NoteParser(tempMIDIParser);
	}
	catch (Exception^ e) {}
	PositionWidth = CurrentNotePictureBox->Width;
	CurrentClef = 0;
	CurrentTempo = 120;
	CurrentDenum = 4;
	CurrentNum = 4;
	PlayButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\play.png");
	RestartButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\restart.png");
	Pausebutton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\pause.png");
	DrawClefs();
	DrawTrack();
	initializeRowsUpDown(domainUpDown1);
	initializeNotesUpDown(domainUpDown2);
	DrawDurations();
	DrawAccidentals();
}

System::Void EditForm::EditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	PreviousForm->Show();
}

System::Void EditForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ path = Directory::GetCurrentDirectory() + "\\temp.midi";
	File::Create(path)->Close();
	MIDIWriter midiWriter(noteParser, path);
}

System::Void EditForm::DrawPosition() {

}

System::Void EditForm::DrawClefs() {
	int x = 0;
	int y = 5;
	int width = Clef1Button->Width;
	int height = Clef2Button->Height;
	Bitmap^ currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetÑlef(currBitMap, Clefs::Treble, width, height, x, y);
	Clef1Button->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetÑlef(currBitMap, Clefs::Bas, width, height, x, y);
	Clef2Button->Image = currBitMap;
}

System::Void EditForm::DrawDurations() {
	int x = 0;
	int y = 5;
	int width = DoubleButton->Width;
	int height = DoubleButton->Height;
	Bitmap^ currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 2, Directions::Up, width, height, x, y);
	DoubleButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 1, Directions::Up, width, height, x, y);
	WholeButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.5, Directions::Up, width, height, x, y);
	HalfButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.25, Directions::Up, width, height, x, y);
	QuarterButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.125, Directions::Up, width, height, x, y);
	EightsButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.0625, Directions::Up, width, height, x, y);
	SixteensButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.03125, Directions::Up, width, height, x, y);
	ThirtyTwosButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
}

System::Void EditForm::DrawAccidentals() {
	int x = 0;
	int y = 0;
	int width = DiezButton->Width;
	int height = DiezButton->Height;
	Bitmap^ currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetSign(currBitMap, Accidentals::Sharp, width, height + 7, x, y - 5);
	DiezButton->Image = currBitMap;
	//CurrentNotePictureBox->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetSign(currBitMap, Accidentals::Flat, width, height + 7, x, y - 5);
	BemolButton->Image = currBitMap;
}

array<int>^ GetLowHigh(List<NormalNote^>^ currentPosition) {
	array<int>^ res = gcnew array<int>(2);
	res[0] = currentPosition[0]->Height;
	res[1] = currentPosition[0]->Height;
	for (int i = 1; i < currentPosition->Count; i++) {
		if (currentPosition[0]->Height < res[0])
			res[0] = currentPosition[0]->Height;
		if (currentPosition[0]->Height > res[1])
			res[0] = currentPosition[0]->Height;
	}
	return res;
}

List<PositionToDraw^>^ GetNotesPositions(List<NormalNote^>^ notes, ClefToDraw^ clef, array<int>^ topBottomLines) {
	List<PositionToDraw^>^ positions = gcnew List<PositionToDraw^>();
	NormalNote^ currentNote;
	int offset = 0;
	int C4Line = 0;
	int difference = 0;
	int lineNumber = 0;
	topBottomLines[0] = 0;
	topBottomLines[0] = 1;
	if (clef->Clef == Clefs::Bas) {
		if (clef->ToneIndex == 0) {
			C4Line = 6;
		}
		else {
			throw "Too high for bass";
		}
	}
	else {
		if (clef->ToneIndex == 0) {
			C4Line = -1;
		}
		else {
			C4Line = -1;
			offset = clef->ToneIndex;
		}
	}
	for (int i = 0; i < notes->Count; i++) {
		PositionToDraw^ pos = gcnew PositionToDraw();
		currentNote = notes[i];
		difference = currentNote->Height - 60 + offset;
		lineNumber = System::Math::Round(difference / double(12 * 7));
		pos->position = lineNumber;
		if (lineNumber < topBottomLines[1])
			topBottomLines[1] = lineNumber;
		if (lineNumber > topBottomLines[0])
			topBottomLines[0] = lineNumber;
		MIDINotes currNote = (MIDINotes)currentNote->Height;
		if (currNote.ToString()->Contains("dies"))
			pos->sign = 2;
		positions->Add(pos);
	}
	return positions;
}

ClefToDraw^ EditForm::RecognizeClef(List<NormalNote^>^ currentPosition) {
	array<int>^ heights = GetLowHigh(currentPosition);
	int lowest = heights[0];
	int highest = heights[1];
	int toneIndex = 0;
	ClefToDraw^ clefToDraw = gcnew ClefToDraw();
	int CFirst = 60;
	if (highest < 64 && lowest < 40) {
		clefToDraw->Clef = Clefs::Bas;
		toneIndex = 0;
		clefToDraw->ToneIndex = 0;
		if (lowest < 31)
			throw "So low note";
		return clefToDraw;
	}
	else if (lowest < 52) {
		clefToDraw->Clef = Clefs::Treble;
		toneIndex = -8;
		clefToDraw->ToneIndex = -12;
		if (lowest < 40)
			throw "So low note";
		return clefToDraw;
	}
	clefToDraw->Clef = Clefs::Treble;
	if (highest > 88) {
		clefToDraw->ToneIndex = 12;
		return clefToDraw;
	}
	clefToDraw->ToneIndex = 0;
	return clefToDraw;
}

bool AreClefsEqual(ClefToDraw^ currClef, ClefToDraw^ prevClef) {
	if ((currClef->Clef != prevClef->Clef) || (currClef->ToneIndex != prevClef->ToneIndex))
		return false;
	return true;
}

PictureBox^ EditForm::CreateAddPictureBox() {
	
	PictureBox^ pictureBox1 = gcnew PictureBox();
	Point startPoint(0, 0);
	pictureBox1->Location = startPoint;
	pictureBox1->Height = PictureBoxHeight;
	pictureBox1->Width = flowLayoutPanel1->Width;
	LineLength = pictureBox1->Width;
	BMPFactory::DrawLines(pictureBox1, CenterLineVerticalOffset, LineLength, HalfLineWidth);
	flowLayoutPanel1->Controls->Add(pictureBox1);
	return pictureBox1;
}

System::Void EditForm::DrawTrack() {
	PictureBox^ currPictureBox = CreateAddPictureBox();
	List<NormalNote^>^ notes = noteParser->NoteLines[0]->Notes;
	int noteCount = notes->Count;

	int rightOffset = LineLength;

	ClefToDraw^ prevClefToDraw = nullptr;
	int currNum = -1;
	int currDenum = -1;
	int currTempo = -1;
	int x;

	List<NormalNote^>^ currentPosition = gcnew List<NormalNote^>();
	ClefToDraw^ clefToDraw = gcnew ClefToDraw();
	currentPosition->Add(notes[0]);
	for (int i = 1; i < noteCount; i++) {
		while (notes[i - 1]->TrackPosition == notes[i]->TrackPosition) {
			currentPosition->Add(notes[i]);
			i++;
		}
		clefToDraw = RecognizeClef(currentPosition);
		if (!(prevClefToDraw == nullptr) && AreClefsEqual(prevClefToDraw, clefToDraw))
			clefToDraw = nullptr;
		else {
			prevClefToDraw = clefToDraw;
			rightOffset -= PositionWidth;
		}
		if ((currDenum != notes[i]->timeSignature->Denumerator) || (currNum != notes[i]->timeSignature->Numerator)) {
			currDenum = notes[i]->timeSignature->Denumerator;
			currNum = notes[i]->timeSignature->Numerator;
			rightOffset -= PositionWidth;
		}
		else {
			currDenum = 0;
			currNum = 0;
		}
		if (currTempo != notes[i]->setTempo->TPQ) {
			currTempo = notes[i]->setTempo->TPQ;
			rightOffset -= PositionWidth;
		}
		else
			currTempo = 0;
		rightOffset -= PositionWidth;
		x = LineLength - rightOffset;
		array<int>^ topBottomLines = gcnew array<int>(2);
		List<PositionToDraw^>^ positions = GetNotesPositions(currentPosition, prevClefToDraw, topBottomLines);
		NotePosition^ currentNodePosition = gcnew NotePosition(currTempo, currNum, currDenum, clefToDraw, positions, topBottomLines[0], topBottomLines[1]);
		if (rightOffset > 0)
			BMPFactory::DrawPosition(CurrentNotePictureBox, CenterLineVerticalOffset, x, PositionWidth, currentNodePosition);
		else {
			currPictureBox = CreateAddPictureBox();
			rightOffset = LineLength;
			x = 0;
			BMPFactory::DrawPosition(CurrentNotePictureBox, CenterLineVerticalOffset, x, PositionWidth, currentNodePosition);
		}
		currentPosition->Clear();	
	}
	int k = 0;
}

void EditForm::initializeRowsUpDown(DomainUpDown^ rowsUpDown) {
	List<String^>^ rows = gcnew List<String^>();
	rows->Add("7.5");
	rows->Add("7");
	rows->Add("6.5");
	rows->Add("6");
	rows->Add("5.5");
	rows->Add("4.5");
	rows->Add("4");
	rows->Add("3.5");
	rows->Add("3");
	rows->Add("2.5");
	rows->Add("2");
	rows->Add("1.5");
	rows->Add("1");
	rows->Add("0.5");
	rows->Add("0");
	rows->Add("-0.5");
	rows->Add("-1");
	rows->Add("-1.5");
	rows->Add("-2");
	rows->Add("-2.5");	
	rowsUpDown->Items->AddRange(rows);
}

System::Void EditForm::initializeNotesUpDown(DomainUpDown^ rowsUpDown) {
	List<String^>^ rows = gcnew List<String^>();
	rows->Add("7.5");
	rows->Add("7");
	rows->Add("6.5");
	rows->Add("6");
	rows->Add("5.5");
	rows->Add("4.5");
	rows->Add("4");
	rows->Add("3.5");
	rows->Add("3");
	rows->Add("2.5");
	rows->Add("2");
	rows->Add("1.5");
	rows->Add("1");
	rows->Add("0.5");
	rows->Add("0");
	rows->Add("-0.5");
	rows->Add("-1");
	rows->Add("-1.5");
	rows->Add("-2");
	rows->Add("-2.5");
	rowsUpDown->Items->AddRange(rows);
}