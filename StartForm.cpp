#include "StartForm.h"
#include "EditForm.h"
#include "PlayerForm.h"

using namespace MIDINoteEditor;
using namespace System;
using namespace System::Windows::Forms;
using namespace Threading;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MIDINoteEditor::StartForm startForm;
	Application::Run(% startForm);
}

System::Void StartForm::FileOpenBtn_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	if (e->Data->GetDataPresent(DataFormats::FileDrop))
		e->Effect = DragDropEffects::All;
	else
		e->Effect = DragDropEffects::None;
}

System::Void StartForm::FileOpenBtn_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	array<String^>^ s = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	String^ fileName = s[0];
	MIDINoteEditor::EditForm^ editForm = gcnew MIDINoteEditor::EditForm(fileName, this);
	this->Hide();
	editForm->Show();
}


System::Void StartForm::PlayerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MIDINoteEditor::PlayerForm^ playerForm = gcnew MIDINoteEditor::PlayerForm(this);
	this->Enabled = false;
	playerForm->Show();
}