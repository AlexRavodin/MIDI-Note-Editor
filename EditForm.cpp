#include "EditForm.h"

using namespace MIDINoteEditor;
using namespace System;
using namespace System::Windows::Forms;

System::Void EditForm::EditForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		MIDIParser^ tempMIDIParser = gcnew MIDIParser(this->FileName);
		tempMIDIParser->PrintStreamToBox(this->StreamTextBox);
	}
	catch (Exception^ e) {}
	color = Color::Black;
	size = 5;
	pen = gcnew Pen(color, size);
	Bitmap^ Lines = gcnew Bitmap(NotePictureBox->Width, NotePictureBox->Height);
	canvas = Graphics::FromImage(Lines);
	NotePictureBox->Image = Lines;
	NotePictureBox->BackColor = Color::White;
}

System::Void EditForm::EditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	PreviousForm->Show();
}