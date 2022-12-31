#include "EditForm.h"

using namespace MIDINoteEditor;
using namespace System;
using namespace System::Windows::Forms;

void ClearBitmap(Bitmap^ bitmap) {
	Graphics^ g = Graphics::FromImage(bitmap);
	g->Clear(Color::White);
}

System::Void EditForm::EditForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->TopMost = true;
	try {
		MIDIParser^ tempMIDIParser = gcnew MIDIParser(this->FileName);
		noteParser = gcnew NoteParser(tempMIDIParser);
	}
	catch (Exception^ e) {}
	PositionWidth = CurrentNotePictureBox->Width / 3;
	CenterLineVerticalOffset = CurrentNotePictureBox->Height / 2;
	LineLength = flowLayoutPanel1->Width;
	CurrentClef = 0;
	CurrentTempo = 120;
	CurrentDenum = 4;
	CurrentNum = 4;
	CurrentNoteDur = 0.25;
	PlayButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\play.png");
	RestartButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\restart.png");
	Pausebutton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\pause.png");
	flowLayoutPanel1->FlowDirection = FlowDirection::TopDown;
	DrawClefs();
	if (noteParser->NoteLines->Count < 1 || noteParser->NoteLines[0]->Notes->Count < 1)
		int a = 0;
	else
		DrawTrack();;
	initializeNotesUpDown(domainUpDown2);
	DrawDurations();
	DrawAccidentals();
	initializeDictionary();
	CurrPos = gcnew List<NormalNote^>();
}

System::Void EditForm::EditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	String^ path = Directory::GetCurrentDirectory() + "\\temp.wav";
	if (File::Exists(path))
	{
		File::Delete(path);
	}
	if (Player != nullptr)
		Player->Stop();
	PreviousForm->Show();
}

System::Void EditForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ path = Directory::GetCurrentDirectory() + "\\temp.midi";
	File::Create(path)->Close();
	MIDIWriter midiWriter(noteParser, path);
}

System::Void EditForm::DrawClefs() {
	int x = 0;
	int y = 5;
	int width = Clef1Button->Width;
	int height = Clef2Button->Height;
	Bitmap^ currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetÑlef(currBitMap, Clefs::Treble, width, height, x, y, 25);
	Clef1Button->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetÑlef(currBitMap, Clefs::Bas, width, height, x, y, 25);
	Clef2Button->Image = currBitMap;
}

System::Void EditForm::DrawDurations() {
	int x = 0;
	int y = 5;
	int width = DoubleButton->Width;
	int height = DoubleButton->Height;
	Bitmap^ currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 2, Directions::Up, width, height, x, y, 35);
	DoubleButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 1, Directions::Up, width, height, x, y, 35);
	WholeButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.5, Directions::Up, width, height, x, y, 35);
	HalfButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.25, Directions::Up, width, height, x, y, 35);
	QuarterButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.125, Directions::Up, width, height, x, y, 35);
	EightsButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.0625, Directions::Up, width, height, x, y, 35);
	SixteensButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetNote(currBitMap, 0.03125, Directions::Up, width, height, x, y, 35);
	ThirtyTwosButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
}

System::Void EditForm::DrawAccidentals() {
	int x = 0;
	int y = 0;
	int width = DiezButton->Width;
	int height = DiezButton->Height;
	Bitmap^ currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetSign(currBitMap, Accidentals::Sharp, width, height + 7, x, y - 5, 30);
	DiezButton->Image = currBitMap;
	currBitMap = gcnew Bitmap(width, height);
	BMPFactory::GetSign(currBitMap, Accidentals::Flat, width, height + 7, x, y - 5, 30);
	BemolButton->Image = currBitMap;
}

array<int>^ GetLowHigh(List<NormalNote^>^ currentPosition) {
	array<int>^ res = gcnew array<int>(2);
	res[0] = currentPosition[0]->Height;
	res[1] = currentPosition[0]->Height;
	for (int i = 1; i < currentPosition->Count; i++) {
		if (currentPosition[i]->Height < res[0])
			res[0] = currentPosition[i]->Height;
		if (currentPosition[i]->Height > res[1])
			res[1] = currentPosition[i]->Height;
	}
	return res;
}

double GetLineNumber(PositionToDraw^ pos, NormalNote^ note, int offset, double C4Line) {
	double difference = note->Height - 60 + offset;
	double coef = 1.0 / 12.0 * 7.0;
	double num = C4Line + difference * coef / 2;
	double withHalf;
	if (num < 0)
		withHalf = Math::Truncate(num) - 0.5;
	else
		withHalf = Math::Truncate(num) + 0.5;
	double remainHalf = Math::Abs(num - withHalf);
	double remain1 = Math::Abs(Math::Abs(num) - Math::Abs(Math::Truncate(num)));
	double remain2 = Math::Abs(Math::Abs(num) - Math::Abs(Math::Round(num)));
	if (remainHalf < remain1) {
		if (remainHalf < remain2)
			return withHalf;
	}
	if (remain1 < remain2)
		return Math::Truncate(num);
	else
		return Math::Round(num);
}

List<PositionToDraw^>^ GetNotesPositions(List<NormalNote^>^ notes, ClefToDraw^ clef, array<double>^ topBottomLines) {
	List<PositionToDraw^>^ positions = gcnew List<PositionToDraw^>();
	int offset = 0;
 	double C4Line = 0;
	topBottomLines[0] = 0;
	topBottomLines[0] = 0;
	if (clef->Clef == Clefs::Bas) {
		if (clef->ToneIndex == 0) {
			C4Line = 6;
		}
	}
	else {
		if (clef->ToneIndex == 0) {
			C4Line = -1;
		}
		else {
			C4Line = 3.5;

		}
	}
	for (int i = 0; i < notes->Count; i++) {
		PositionToDraw^ pos = gcnew PositionToDraw();
		pos->lineNumber = GetLineNumber(pos, notes[i], offset, C4Line);
		if (pos->lineNumber > 5.5) {
			if (pos->lineNumber > topBottomLines[0] + 5.0)
				topBottomLines[0] = pos->lineNumber - 5.0;
		}
		if (pos->lineNumber < -0.5) {
			if (pos->lineNumber < topBottomLines[1])
				topBottomLines[1] = pos->lineNumber;
		}
		MIDINotes currNote = (MIDINotes)notes[i]->Height;
		if (currNote.ToString()->Contains("dies"))
			pos->sign = 2;
		pos->length = notes[i]->Length;
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
	if (lowest > 64 && highest > 64) {
		clefToDraw->Clef = Clefs::Treble;
		clefToDraw->ToneIndex = 0;
	}
	else if (lowest > 64 && highest < 70 ) {
		clefToDraw->Clef = Clefs::Treble;
		clefToDraw->ToneIndex = 0;
	}
	else {
		clefToDraw->Clef = Clefs::Treble;
		clefToDraw->ToneIndex = -12;
	}
	return clefToDraw;
}

bool EditForm::ClefChanged(ClefToDraw^ currClef, List<NormalNote^>^ currentPosition) {
	ClefToDraw^ newCleff = gcnew ClefToDraw();
	newCleff->Clef = Clefs::Treble;
	newCleff->ToneIndex = -12;
	newCleff = RecognizeClef(currentPosition);
	if ((currClef->Clef != newCleff->Clef) || (currClef->ToneIndex != newCleff->ToneIndex)) {
		currClef->Clef = newCleff->Clef;
		currClef->ToneIndex = newCleff->ToneIndex;
		return true;
	}
	return false;
}

bool MetreChanged(array<int>^ metre, NormalNote^ note) {
	if (metre[0] != note->timeSignature->Numerator || metre[1] != note->timeSignature->Denumerator) {
		metre[0] = note->timeSignature->Numerator;
		metre[1] = note->timeSignature->Denumerator;
		return true;
	}
	return false;
}
bool TempoChanged(int^ currentTempo, NormalNote^ note) {
	if (*currentTempo != note->setTempo->TPQ) {
		currentTempo = note->setTempo->TPQ;
		return true;
	}
	return false;
}

PictureBox^ EditForm::CreateAddPictureBox() {
	PictureBox^ currPictureBox = gcnew PictureBox();
	PictureBoxNumber++;
	Bitmap^ bitmap = gcnew Bitmap(flowLayoutPanel1->Width * 0.99, PictureBoxHeight);
	currPictureBox->Height = PictureBoxHeight;
	currPictureBox->Width = flowLayoutPanel1->Width * 0.99;
	currPictureBox->Image = bitmap;
	BMPFactory::DrawLines(currPictureBox, CenterLineVerticalOffset, LineLength, HalfLineWidth);
	flowLayoutPanel1->Controls->Add(currPictureBox);
	flowLayoutPanel1->Update();
	return currPictureBox;
}

System::Void EditForm::DrawTrack() {
	flowLayoutPanel1->Controls->Clear();
	int trackPosNum = 0;
	PictureBox^ CurrentNotePictureBox = CreateAddPictureBox();
	List<NormalNote^>^ notes = noteParser->NoteLines[0]->Notes;
	int noteCount = notes->Count;
	if (noteCount < 1)
		return;
	array<double>^ topBottomLines = gcnew array<double>(2);
	array<int>^ metre = gcnew array<int>(2);

	int^ currTempo = gcnew int(notes[0]->setTempo->TPQ);
	metre[0] = -1;
	metre[1] = -1;

	ClefToDraw^ clefToDraw = gcnew ClefToDraw();
	clefToDraw->Clef = Clefs::Bas;
	clefToDraw->ToneIndex = -100;
	int x = 25;

	bool clefChanged, metreChanged, tempoChanged;
	int k = 0;
	List<NormalNote^>^ currentPosition = gcnew List<NormalNote^>();
	for (int i = 1; i < noteCount; i++) {
		k++;
		int posLength = 0;
		currentPosition->Add(notes[i - 1]);
		while ((i < noteCount) && (notes[i - 1]->TrackPosition == notes[i]->TrackPosition)) {
			currentPosition->Add(notes[i]);
			i++;
		}
		clefChanged = ClefChanged(clefToDraw, currentPosition);
		metreChanged = MetreChanged(metre, currentPosition[0]);
		tempoChanged = TempoChanged(currTempo, currentPosition[0]);
		if (clefChanged) {
			posLength += PositionWidth / 2;
		}
		if (metreChanged) {
			posLength += PositionWidth;
		}
		posLength += PositionWidth;

		List<PositionToDraw^>^ positions = GetNotesPositions(currentPosition, clefToDraw, topBottomLines);
		NotePosition^ currentNotePosition = gcnew NotePosition(*currTempo, metre, clefToDraw, positions, topBottomLines, tempoChanged, clefChanged, metreChanged);

		if (x + posLength + 350 < LineLength) {
			BMPFactory::DrawPosition(CurrentNotePictureBox, CenterLineVerticalOffset, PositionWidth, HalfLineWidth, x, currentNotePosition, trackPosNum, DrawPoses, DrawExtra);
			x += posLength;
		}
		else {
			CurrentNotePictureBox = CreateAddPictureBox();
			x = 25;
			BMPFactory::DrawPosition(CurrentNotePictureBox, CenterLineVerticalOffset, PositionWidth, HalfLineWidth, x, currentNotePosition, trackPosNum, DrawPoses, DrawExtra);
			x += posLength;
		}
		trackPosNum++;
		currentPosition->Clear();
	}
}

void EditForm::DrawNote() {
	CurrentNotePictureBox->Image= nullptr;
	if (CurrPos->Count < 1)
		return;
	array<double>^ topBottomLines = gcnew array<double>(2);
	array<int>^ metre = gcnew array<int>(2);

	int^ currTempo = gcnew int(0);
	metre[0] = -1;
	metre[1] = -1;
	int posLength = 0;
	int x = 10;

	ClefToDraw^ clefToDraw = gcnew ClefToDraw();
	clefToDraw->Clef = Clefs::Bas;
	clefToDraw->ToneIndex = -100;

	bool clefChanged, metreChanged, tempoChanged;

	clefChanged = ClefChanged(clefToDraw, CurrPos);
	metreChanged = MetreChanged(metre, CurrPos[0]);
	tempoChanged = TempoChanged(currTempo, CurrPos[0]);

	if (clefChanged) {
		posLength += PositionWidth / 2;
	}
	if (metreChanged) {
		posLength += PositionWidth;
	}
	posLength += PositionWidth;

	List<PositionToDraw^>^ positions = GetNotesPositions(CurrPos, clefToDraw, topBottomLines);
	NotePosition^ currentNotePosition = gcnew NotePosition(*currTempo, metre, clefToDraw, positions, topBottomLines, tempoChanged, clefChanged, metreChanged);
	BMPFactory::DrawLines(CurrentNotePictureBox, CenterLineVerticalOffset, LineLength, HalfLineWidth);
	BMPFactory::DrawPosition(CurrentNotePictureBox, CenterLineVerticalOffset, PositionWidth, HalfLineWidth, x, currentNotePosition, 0, false, DrawExtra);
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
	rows->Add("C1");
	rows->Add("D1");
	rows->Add("E1");
	rows->Add("F1");
	rows->Add("G1");
	rows->Add("A1");
	rows->Add("B1");

	rows->Add("C2");
	rows->Add("D2");
	rows->Add("E2");
	rows->Add("F2");
	rows->Add("G2");
	rows->Add("A2");
	rows->Add("B2");

	rows->Add("C3");
	rows->Add("D3");
	rows->Add("E3");
	rows->Add("F3");
	rows->Add("G3");
	rows->Add("A3");
	rows->Add("B3");

	rows->Add("C4");
	rows->Add("D4");
	rows->Add("E4");
	rows->Add("F4");
	rows->Add("G4");
	rows->Add("A4");
	rows->Add("B4");

	rows->Add("C5");
	rows->Add("D5");
	rows->Add("E5");
	rows->Add("F5");
	rows->Add("G5");
	rows->Add("A5");
	rows->Add("B5");
	
	rowsUpDown->Items->AddRange(rows);
}

System::Void EditForm::initializeDictionary() {
	NoteToHeight = gcnew Dictionary<String^, int>();
	NoteToHeight->Add("C1", 24);
	NoteToHeight->Add("D1", 26);
	NoteToHeight->Add("E1", 28);
	NoteToHeight->Add("F1", 29);
	NoteToHeight->Add("G1", 31);
	NoteToHeight->Add("A1", 33);
	NoteToHeight->Add("B1", 35);

	NoteToHeight->Add("C2", 36);
	NoteToHeight->Add("D2", 38);
	NoteToHeight->Add("E2", 40);
	NoteToHeight->Add("F2", 41);
	NoteToHeight->Add("G2", 43);
	NoteToHeight->Add("A2", 45);
	NoteToHeight->Add("B2", 47);

	NoteToHeight->Add("C3", 48);
	NoteToHeight->Add("D3", 50);
	NoteToHeight->Add("E3", 52);
	NoteToHeight->Add("F3", 53);
	NoteToHeight->Add("G3", 55);
	NoteToHeight->Add("A3", 57);
	NoteToHeight->Add("B3", 59);

	NoteToHeight->Add("C4", 60);
	NoteToHeight->Add("D4", 62);
	NoteToHeight->Add("E4", 64);
	NoteToHeight->Add("F4", 65);
	NoteToHeight->Add("G4", 67);
	NoteToHeight->Add("A4", 69);
	NoteToHeight->Add("B4", 71);

	NoteToHeight->Add("C5", 72);
	NoteToHeight->Add("D5", 74);
	NoteToHeight->Add("E5", 76);
	NoteToHeight->Add("F5", 77);
	NoteToHeight->Add("G5", 79);
	NoteToHeight->Add("A5", 81);
	NoteToHeight->Add("B5", 83);
}