#pragma once
#include "EditForm.h"
#include "LogsForm.h"
#include "SettingsForm.h"

namespace MIDINoteEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ FileOpenButton;
	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ FileCreateButton;
	private: System::Windows::Forms::Button^ PlayerButton;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;


	protected:

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
			this->FileOpenButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileCreateButton = (gcnew System::Windows::Forms::Button());
			this->PlayerButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// FileOpenButton
			// 
			this->FileOpenButton->AllowDrop = true;
			this->FileOpenButton->BackColor = System::Drawing::Color::Transparent;
			this->FileOpenButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->FileOpenButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->FileOpenButton->FlatAppearance->BorderSize = 0;
			this->FileOpenButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Window;
			this->FileOpenButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->FileOpenButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FileOpenButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->FileOpenButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->FileOpenButton->Location = System::Drawing::Point(18, 188);
			this->FileOpenButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->FileOpenButton->Name = L"FileOpenButton";
			this->FileOpenButton->Size = System::Drawing::Size(298, 78);
			this->FileOpenButton->TabIndex = 1;
			this->FileOpenButton->Text = L"������� ����";
			this->FileOpenButton->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->FileOpenButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->FileOpenButton->UseVisualStyleBackColor = false;
			this->FileOpenButton->Click += gcnew System::EventHandler(this, &StartForm::FileOpenBtn_Click);
			this->FileOpenButton->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &StartForm::FileOpenBtn_DragDrop);
			this->FileOpenButton->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &StartForm::FileOpenBtn_DragEnter);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 31.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(2, 39);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(664, 58);
			this->label1->TabIndex = 1;
			this->label1->Text = L"����� ���������� � �������� ���";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->����ToolStripMenuItem,
					this->����ToolStripMenuItem, this->���������ToolStripMenuItem, this->�������ToolStripMenuItem, this->�������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(746, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(57, 24);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::����ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::����ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(96, 24);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D1));
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(79, 24);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::�������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(133, 24);
			this->�������������ToolStripMenuItem->Text = L"� ������������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::�������������ToolStripMenuItem_Click);
			// 
			// FileCreateButton
			// 
			this->FileCreateButton->BackColor = System::Drawing::Color::Transparent;
			this->FileCreateButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->FileCreateButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->FileCreateButton->FlatAppearance->BorderSize = 0;
			this->FileCreateButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Window;
			this->FileCreateButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->FileCreateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FileCreateButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->FileCreateButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->FileCreateButton->Location = System::Drawing::Point(18, 104);
			this->FileCreateButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->FileCreateButton->Name = L"FileCreateButton";
			this->FileCreateButton->Padding = System::Windows::Forms::Padding(0, 0, 11, 0);
			this->FileCreateButton->Size = System::Drawing::Size(298, 78);
			this->FileCreateButton->TabIndex = 0;
			this->FileCreateButton->Text = L"������� ����";
			this->FileCreateButton->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->FileCreateButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->FileCreateButton->UseVisualStyleBackColor = false;
			this->FileCreateButton->Click += gcnew System::EventHandler(this, &StartForm::FileCreateButton_Click);
			// 
			// PlayerButton
			// 
			this->PlayerButton->AllowDrop = true;
			this->PlayerButton->BackColor = System::Drawing::Color::Transparent;
			this->PlayerButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->PlayerButton->FlatAppearance->BorderSize = 0;
			this->PlayerButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Window;
			this->PlayerButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->PlayerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PlayerButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PlayerButton->Location = System::Drawing::Point(384, 306);
			this->PlayerButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PlayerButton->Name = L"PlayerButton";
			this->PlayerButton->Size = System::Drawing::Size(336, 78);
			this->PlayerButton->TabIndex = 2;
			this->PlayerButton->Text = L"�������� �������������";
			this->PlayerButton->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->PlayerButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->PlayerButton->UseVisualStyleBackColor = false;
			this->PlayerButton->Click += gcnew System::EventHandler(this, &StartForm::PlayerButton_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(746, 393);
			this->Controls->Add(this->PlayerButton);
			this->Controls->Add(this->FileCreateButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->FileOpenButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��������� ����";
			this->Load += gcnew System::EventHandler(this, &StartForm::StartForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FileOpenBtn_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void FileOpenBtn_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void FileOpenBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
		fileDialog->InitialDirectory = Directory::GetCurrentDirectory() + "\\MIDI";
		fileDialog->Filter = "mid file (*mid)|*.mid";
		String^ path = "";
		if (fileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			path = fileDialog->FileName;
			MIDINoteEditor::EditForm^ editForm = gcnew MIDINoteEditor::EditForm(path, this);
			this->Hide();
			editForm->Show();
		}
	}

	private: System::Void StartForm_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ path = System::IO::Path::GetDirectoryName(Application::ExecutablePath);
		FileOpenButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\searchFile.png");
		FileCreateButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\newFile.png");
		PlayerButton->Image = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\musicPlayer.png");
		this->BackgroundImage = Image::FromFile(Directory::GetCurrentDirectory() + "\\Icons\\startBackground.png");
		this->TopMost = true;
		label1->BackColor = Color::Transparent;
	}
	private: System::Void FileCreateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		MIDINoteEditor::EditForm^ editForm = gcnew MIDINoteEditor::EditForm("", this);
		this->Hide();
		editForm->Show();
	}
private: System::Void PlayerButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ fullFileName = Directory::GetCurrentDirectory() + "\\logs.txt";
	if (File::Exists(fullFileName))
	{
		StreamReader^ textStream = File::OpenText(fullFileName);
		StringBuilder^ logs = gcnew StringBuilder();
		String^ str;
		while ((str = textStream->ReadLine()) != nullptr){
			logs->AppendLine(str);
		}
		LogsForm^ logForm = gcnew LogsForm(logs, this);
		logForm->Show();
		this->Enabled = false;
	}
}
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ info = "��������� ���� ����������:\n\n" + "���� - ����� ����, ����� �������.\n" + "���� - ���������� � �������� ������� �����.\n"
		+ "��������� - ����� ������� ���������� �� ��������� � Soundfont.\n" + "������� - ������� ��������� � ����������.\n" 
		+ "� ������������ - ���������� � ���������.\n\n" + "������� ���� - �������� ������� �����.\n" + "������� ���� - ����� �������������.\n"
		+ "������� ������������� - ������� ���� ��� ���������������.";
	MessageBox::Show(info, "�������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������� ���������\n������ 151002", "� ������������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
	fileDialog->InitialDirectory = Directory::GetCurrentDirectory() + "\\MIDI";
	fileDialog->Filter = "mid file (*mid)|*.mid";
	String^ path = "";
	if (fileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		path = fileDialog->FileName;
		MIDINoteEditor::EditForm^ editForm = gcnew MIDINoteEditor::EditForm(path, this);
		this->Hide();
		editForm->Show();
	}
}
private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	SettingsForm^ settingsForm = gcnew SettingsForm(this);
	settingsForm->Show();
	this->Enabled = false;
}
};

}