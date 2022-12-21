#pragma once
#include "FormatConverter.h"

namespace MIDINoteEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Media;

	/// <summary>
	/// Summary for Player
	/// </summary>
	public ref class PlayerForm : public System::Windows::Forms::Form
	{
	public:
		PlayerForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		PlayerForm(Form^ previousForm, String^ currentSoundfont)
		{
			InitializeComponent();
			this->PreviousForm = previousForm;
			this->CurrentSoundfont = currentSoundfont;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PlayerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: Form^ PreviousForm;
	private: String^ CurrentSoundfont;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 64);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PlayerForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Window;
			this->button2->Location = System::Drawing::Point(112, 8);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 64);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// PlayerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 79);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PlayerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Проигрыватель";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PlayerForm::PlayerForm_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
		fileDialog->InitialDirectory = Directory::GetCurrentDirectory() + "\\Tracks";
		fileDialog->Filter = "all files(*)|*.*|mid file (*mid)|*.mid|wav file (*wav)|*.wav";
		String^ fileName = "";
		String^ tempFileName = Directory::GetCurrentDirectory() + "\\Tracks\\temp.wav";
		if (fileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			fileName = fileDialog->FileName;
			FileInfo^ fileInfo = gcnew FileInfo(fileName);
			if (fileInfo->Extension == ".mid") {
				FormatConverter::ConvertMIDI("WAV", fileName, tempFileName, CurrentSoundfont, 0);
				SoundPlayer^ player = gcnew SoundPlayer(tempFileName);
				player->Play();
			}
			if (fileInfo->Extension == ".mp3") {
				SoundPlayer^ player = gcnew SoundPlayer(fileName);
				player->Play();
			}
			else if (fileInfo->Extension == ".wav") {

				SoundPlayer^ player = gcnew SoundPlayer(fileName);
				player->Play();
			}
			else
				MessageBox::Show("Неверный формат файла.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void PlayerForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		PreviousForm->Show();
	}
};
}
