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
	using namespace System::Windows;

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
		PlayerForm(Form^ previousForm)
		{
			InitializeComponent();
			this->PreviousForm = previousForm;
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
	private: SoundPlayer^ Player;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Location = System::Drawing::Point(1, 6);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 52);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PlayerForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Control;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->Location = System::Drawing::Point(56, 6);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 52);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &PlayerForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Control;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->Location = System::Drawing::Point(240, 4);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 52);
			this->button3->TabIndex = 4;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &PlayerForm::button3_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::Control;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->Location = System::Drawing::Point(180, 6);
			this->button5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(60, 52);
			this->button5->TabIndex = 3;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &PlayerForm::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Control;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->Location = System::Drawing::Point(120, 6);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(60, 52);
			this->button4->TabIndex = 2;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &PlayerForm::button4_Click);
			// 
			// PlayerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(298, 59);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PlayerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Проигрыватель";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PlayerForm::PlayerForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &PlayerForm::PlayerForm_Load);
			this->Shown += gcnew System::EventHandler(this, &PlayerForm::PlayerForm_Shown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
		List<String^>^ settings = GetSettings();
		fileDialog->InitialDirectory = Directory::GetCurrentDirectory() + "\\Tracks\\";
		fileDialog->Filter = "all files(*)|*.*|mid file (*mid)|*.mid|wav file (*wav)|*.wav";
		String^ fileName = "";
		String^ tempFileName = Directory::GetCurrentDirectory() + "\\Tracks\\temp.wav";
		if (File::Exists(tempFileName))
		{
			File::Delete(tempFileName);
		}
		if (fileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			fileName = fileDialog->FileName;
			FileInfo^ fileInfo = gcnew FileInfo(fileName);
			if (fileInfo->Extension == ".mid" || fileInfo->Extension == ".mp3") {
				try {
					FormatConverter::ConvertMIDI("WAV", fileName, tempFileName, settings[0]);
					System::Threading::Thread::Sleep(2000);
					Player = gcnew SoundPlayer(tempFileName);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Некорректный файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else if (fileInfo->Extension == ".wav") {
				Player = gcnew SoundPlayer(fileName);
			}
			else
				MessageBox::Show("Неверный формат файла.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void PlayerForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		PreviousForm->Show();
		Player->Stop();
		PreviousForm->Enabled = true;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		PreviousForm->Show();
		PreviousForm->Enabled = true;
		Player->Stop();
		this->Close();
	}
	private: System::Void PlayerForm_Load(System::Object^ sender, System::EventArgs^ e) {
		button1->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\searchFile48.png");
		button2->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\play.png");
		button3->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\close.png");
		button5->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\restart.png");
		button4->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\pause.png");

	}

	private: List<String^>^ GetSettings() {
		List<String^>^ defaultSettings = gcnew List<String^>();
		defaultSettings->Add(Directory::GetCurrentDirectory() + "\\Tracks");
		defaultSettings->Add(Directory::GetCurrentDirectory() + "\\Soundfonts\\5_rhodes3.sf2");
		String^ settingsFilePath = Directory::GetCurrentDirectory() + "\\settings.txt";
		if (!File::Exists(settingsFilePath)) {
			File::Create(settingsFilePath);
			StreamWriter^ settingsWriter = gcnew StreamWriter(settingsFilePath);
			settingsWriter->WriteLine(defaultSettings[1]);
			settingsWriter->WriteLine(defaultSettings[0]);
			settingsWriter->Close();
		}
		List<String^>^ settings = gcnew List<String^>();
		TextReader^ settingsReader = File::OpenText(settingsFilePath);
		settings->Add(settingsReader->ReadLine());
		settings->Add(settingsReader->ReadLine());
		settingsReader->Close();
		return settings;
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Player != nullptr)
			Player->PlayLooping();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Player != nullptr)
			Player->PlayLooping();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Player != nullptr)
			Player->Stop();
	}
	private: System::Void PlayerForm_Shown(System::Object^ sender, System::EventArgs^ e) {
		this->TopMost = true;
	}
	};
}
