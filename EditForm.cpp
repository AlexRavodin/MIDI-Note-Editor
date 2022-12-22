#include "EditForm.h"

using namespace MIDINoteEditor;
using namespace System;
using namespace System::Windows::Forms;

System::Void EditForm::EditForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		MIDIParser^ tempMIDIParser = gcnew MIDIParser(this->FileName);
		//tempMIDIParser->PrintStreamToBox(this->StreamTextBox);
		NoteParser^ noteParser = gcnew NoteParser(tempMIDIParser);
		int k = 0;
	}
	catch (Exception^ e) {}
	color = Color::Black;
	size = 5;
	pen = gcnew Pen(color, size);
	//Bitmap^ Lines = gcnew Bitmap(NotePictureBox->Width, NotePictureBox->Height);
	//canvas = Graphics::FromImage(Lines);
	//NotePictureBox->Image = Lines;
	//NotePictureBox->BackColor = Color::White;
	//Clef2Button->Visible = true;
	Clef^ clef = gcnew Clef();
	Clef1Button->Image = BMPFactory::Get�lef(Clefs::Treble);
	Clef2Button->Image = BMPFactory::Get�lef(Clefs::Bas);
	//NotePictureBox->Image = BMPFactory::Get�lef(Clefs::Treble);
}

System::Void EditForm::EditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	PreviousForm->Show();
}