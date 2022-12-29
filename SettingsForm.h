#pragma once

namespace MIDINoteEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SettingsForm(Form^ previousForm)
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
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	String^ SoundFontName;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: String^ CurrentSoundfont;
	private: String^ CurrentDirectory;
	private: Form^ PreviousForm;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(387, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Текущее место сохранения файлов:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(292, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Нажмите, чтобы изменить";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(221, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Текущий soundfont:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(8, 136);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(292, 25);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Нажмите, чтобы изменить";
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(472, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Изменить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SettingsForm::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(472, 96);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 31);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SettingsForm::button2_Click);
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(598, 169);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройки";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SettingsForm::SettingsForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->Shown += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void WriteNewFileNames(List<String^>^ newStrings) {
			String^ fullFileName = Directory::GetCurrentDirectory() + "\\settings.txt";
			StreamWriter^ textStream = gcnew StreamWriter(fullFileName, false);
			for (int i = 0; i < newStrings->Count; i++)
				textStream->WriteLine(newStrings[i]);
			textStream->Close();
		}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
		fileDialog->InitialDirectory = Directory::GetCurrentDirectory() + "\\Soundfonts\\";
		fileDialog->Filter = "SF file|*.sf2";
		String^ path = "";
		String^ sf = "";
		if (fileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			sf = fileDialog->FileName;
			List<String^>^ newStrings = gcnew List<String^>();
			newStrings->Add(sf);
			newStrings->Add(GetSettings()[1]);
			WriteNewFileNames(newStrings);
		}
		label5->Text = GetSettings()[0];
	}
private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: List<String^>^ GetSettings() {
		   List<String^>^ defaultSettings = gcnew List<String^>();
		   defaultSettings->Add(Directory::GetCurrentDirectory() + "\\Tracks");
		   defaultSettings->Add(Directory::GetCurrentDirectory() + "\\Soundfonts\\5_rhodes3.sf2");
		   String^ settingsFilePath = Directory::GetCurrentDirectory() + "\\settings.txt";
		   if (!File::Exists(settingsFilePath)) {
			   StreamWriter^ settingsWriter = File::CreateText(settingsFilePath);
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
private: System::Void SettingsForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	label4->Text = GetSettings()[1];
	label5->Text = GetSettings()[0];
	this->TopMost = true;
}
private: System::Void SettingsForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	PreviousForm->Enabled = true;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ newFolderName = "";
	FolderBrowserDialog^ fileDialog = gcnew FolderBrowserDialog();
	fileDialog->ShowNewFolderButton = false; 
	fileDialog->RootFolder = Environment::SpecialFolder::MyComputer;
	if (fileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		newFolderName = fileDialog->SelectedPath;
		List<String^>^ newStrings = gcnew List<String^>();
		newStrings->Add(GetSettings()[0]);
		newStrings->Add(newFolderName);
		WriteNewFileNames(newStrings);
	}
	label4->Text = GetSettings()[1];
}
};
}
