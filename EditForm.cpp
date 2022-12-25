#include "EditForm.h"

using namespace MIDINoteEditor;
using namespace System;
using namespace System::Windows::Forms;

System::Void EditForm::EditForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		MIDIParser^ tempMIDIParser = gcnew MIDIParser(this->FileName);
		noteParser = gcnew NoteParser(tempMIDIParser);
	}
	catch (Exception^ e) {}
	color = Color::Black;
	size = 5;
	pen = gcnew Pen(color, size);
	Clef^ clef = gcnew Clef();
	Clef1Button->Image = BMPFactory::Get—lef(Clefs::Treble);
	Clef2Button->Image = BMPFactory::Get—lef(Clefs::Bas);
	PlayButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\play.png");
	RestartButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\restart.png");
	Pausebutton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\pause.png");
	DrawClefs();
	DrawTrack();
	initializeRowsUpDown(domainUpDown1);
	initializeNotesUpDown(domainUpDown2);
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
	Clef1Button->Image = BMPFactory::Get—lef(Clefs::Treble);
	Clef2Button->Image = BMPFactory::Get—lef(Clefs::Bas);
}

System::Void EditForm::DrawDurations() {

}

System::Void EditForm::DrawAccidentals() {

}

int EditForm::RecognizeClef(int highest, int lowest) {
	int octaveIndex = 0;
	int CFirst = 60;
	//if (CFirst - lowest < )
	return 0;
}

System::Void EditForm::DrawTrack() {
	PictureBox^ currPictureBox;
	List<NormalNote^>^ notes = noteParser->NoteLines[0]->Notes;
	int noteCount = notes->Count;
	PictureBox^ pictureBox1 = gcnew PictureBox();
	Point startPoint(0, 0);
	pictureBox1->Location = startPoint;
	pictureBox1->Height = PictureBoxHeight;
	pictureBox1->Width = flowLayoutPanel1->Width;
	LineLength = pictureBox1->Width;
	BMPFactory::DrawLines(pictureBox1, CenterLineVerticalOffset, LineLength, HalfLineWidth);
	flowLayoutPanel1->Controls->Add(pictureBox1);

	int widthCoef = 0;
	int leftoffset;

	int currClef = -1;
	int currNum = -1;
	int currDenum = -1;
	int currTempo = -1;

	//int newTempo, newClef, new = 0;
	/*
	for (int i = 0; i < noteCount; i++) {
		widthCoef = 0;
		if (notes[i]->setTempo->TPQ != currTempo) {
			currTempo = notes[i]->setTempo->TPQ;
			widthCoef++;
		}
		if ((notes[i]->timeSignature->Numerator != currNum) || (notes[i]->timeSignature->Denumerator != currDenum)) {
			currTempo = notes[i]->setTempo->TPQ;

			widthCoef++;
		}
		if ((notes[i]->timeSignature->Numerator != currNum) || (notes[i]->timeSignature->Denumerator != currDenum)) {
			currTempo = notes[i]->setTempo->TPQ;

			widthCoef++;
		}
		if (widthCoef * PositionWidth > rightOffset) {

		}
		else
			BMPFactory::DrawPosition();
	}
	*/
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

System::Void initializeNotesUpDown(DomainUpDown^ rowsUpDown) {
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