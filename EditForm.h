#pragma once
#include "MIDIParser.h"
#include "BMPFactory.h"
#include "NoteParser.h"
#include "MIDIWriter.h"

namespace MIDINoteEditor {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditForm
	/// </summary>
	public ref class EditForm : public System::Windows::Forms::Form
	{
	public:
		EditForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		EditForm(String^ fileName, Form^ previousForm)
		{
			InitializeComponent();
			this->FileName = fileName;
			this->PreviousForm = previousForm;
			this->CenterLineVerticalOffset = 100;
			this->HalfLineWidth = 20;
			this->LineLength = 600;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		String^ FileName;
		Form^ PreviousForm;
		Bitmap^ BackGroundBMP;
		NoteParser^ noteParser;
	private: System::Windows::Forms::TextBox^ StreamTextBox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStrip^ NotesToolStrip;
	private: System::Windows::Forms::PictureBox^ NotesPictureBox;


	private:
		Graphics^ canvas;
		List <Point>^ points;
		Pen^ pen;
		bool draw;
		Bitmap^ background;
		Color color;
		float size;
		bool clearAll;
		int statePen;
		int CenterLineVerticalOffset;
		int HalfLineWidth;
		int LineLength;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ правкаToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;

	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton6;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton7;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton11;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton10;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton9;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton8;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton12;
	private: System::Windows::Forms::ToolStrip^ ClefsToolStrip;
	private: System::Windows::Forms::ToolStripButton^ Clef1Button;
	private: System::Windows::Forms::ToolStripButton^ Clef2Button;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;

private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::PictureBox^ CurrentNotePictureBox;
private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ToolStripMenuItem^ midiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mp3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ wavToolStripMenuItem;
	private: System::Windows::Forms::Button^ button2;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditForm::typeid));
			this->StreamTextBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->NotesToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton11 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton10 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton12 = (gcnew System::Windows::Forms::ToolStripButton());
			this->NotesPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->midiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mp3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wavToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ClefsToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->Clef1Button = (gcnew System::Windows::Forms::ToolStripButton());
			this->Clef2Button = (gcnew System::Windows::Forms::ToolStripButton());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->CurrentNotePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->NotesToolStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NotesPictureBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->ClefsToolStrip->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentNotePictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// StreamTextBox
			// 
			this->StreamTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->StreamTextBox->Location = System::Drawing::Point(1112, 152);
			this->StreamTextBox->Multiline = true;
			this->StreamTextBox->Name = L"StreamTextBox";
			this->StreamTextBox->Size = System::Drawing::Size(184, 68);
			this->StreamTextBox->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(776, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(276, 56);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditForm::button1_Click);
			// 
			// NotesToolStrip
			// 
			this->NotesToolStrip->AutoSize = false;
			this->NotesToolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->NotesToolStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->NotesToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->toolStripButton1,
					this->toolStripButton3, this->toolStripButton2, this->toolStripButton5, this->toolStripButton4, this->toolStripButton6, this->toolStripButton7,
					this->toolStripButton11, this->toolStripButton10, this->toolStripButton9, this->toolStripButton8, this->toolStripButton12
			});
			this->NotesToolStrip->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->NotesToolStrip->Location = System::Drawing::Point(144, 8);
			this->NotesToolStrip->Name = L"NotesToolStrip";
			this->NotesToolStrip->Size = System::Drawing::Size(246, 83);
			this->NotesToolStrip->TabIndex = 3;
			this->NotesToolStrip->Text = L"w";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->AutoSize = false;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(29, 24);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->AutoSize = false;
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(29, 24);
			this->toolStripButton3->Text = L"toolStripButton3";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->AutoSize = false;
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(29, 24);
			this->toolStripButton2->Text = L"toolStripButton2";
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->AutoSize = false;
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(29, 24);
			this->toolStripButton5->Text = L"toolStripButton5";
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->AutoSize = false;
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(29, 24);
			this->toolStripButton4->Text = L"toolStripButton4";
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->AutoSize = false;
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 40));
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Margin = System::Windows::Forms::Padding(1);
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(40, 40);
			this->toolStripButton6->Text = L"toolStripButton6";
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->AutoSize = false;
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(50, 50);
			this->toolStripButton7->Text = L"toolStripButton7";
			// 
			// toolStripButton11
			// 
			this->toolStripButton11->AutoSize = false;
			this->toolStripButton11->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton11.Image")));
			this->toolStripButton11->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton11->Name = L"toolStripButton11";
			this->toolStripButton11->Size = System::Drawing::Size(29, 24);
			this->toolStripButton11->Text = L"toolStripButton1";
			// 
			// toolStripButton10
			// 
			this->toolStripButton10->AutoSize = false;
			this->toolStripButton10->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton10.Image")));
			this->toolStripButton10->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton10->Name = L"toolStripButton10";
			this->toolStripButton10->Size = System::Drawing::Size(29, 24);
			this->toolStripButton10->Text = L"toolStripButton1";
			// 
			// toolStripButton9
			// 
			this->toolStripButton9->AutoSize = false;
			this->toolStripButton9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton9.Image")));
			this->toolStripButton9->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton9->Name = L"toolStripButton9";
			this->toolStripButton9->Size = System::Drawing::Size(29, 24);
			this->toolStripButton9->Text = L"toolStripButton1";
			// 
			// toolStripButton8
			// 
			this->toolStripButton8->AutoSize = false;
			this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton8.Image")));
			this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton8->Name = L"toolStripButton8";
			this->toolStripButton8->Size = System::Drawing::Size(29, 24);
			this->toolStripButton8->Text = L"toolStripButton1";
			// 
			// toolStripButton12
			// 
			this->toolStripButton12->AutoSize = false;
			this->toolStripButton12->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton12.Image")));
			this->toolStripButton12->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton12->Name = L"toolStripButton12";
			this->toolStripButton12->Size = System::Drawing::Size(29, 24);
			this->toolStripButton12->Text = L"toolStripButton1";
			// 
			// NotesPictureBox
			// 
			this->NotesPictureBox->Location = System::Drawing::Point(3, 3);
			this->NotesPictureBox->Name = L"NotesPictureBox";
			this->NotesPictureBox->Size = System::Drawing::Size(1381, 129);
			this->NotesPictureBox->TabIndex = 4;
			this->NotesPictureBox->TabStop = false;
			this->NotesPictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EditForm::pictureBox1_Paint);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->файлToolStripMenuItem,
					this->правкаToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1482, 28);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->midiToolStripMenuItem,
					this->mp3ToolStripMenuItem, this->wavToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(97, 24);
			this->файлToolStripMenuItem->Text = L"Сохранить";
			// 
			// midiToolStripMenuItem
			// 
			this->midiToolStripMenuItem->Name = L"midiToolStripMenuItem";
			this->midiToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->midiToolStripMenuItem->Text = L"midi";
			// 
			// mp3ToolStripMenuItem
			// 
			this->mp3ToolStripMenuItem->Name = L"mp3ToolStripMenuItem";
			this->mp3ToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->mp3ToolStripMenuItem->Text = L"mp3";
			// 
			// wavToolStripMenuItem
			// 
			this->wavToolStripMenuItem->Name = L"wavToolStripMenuItem";
			this->wavToolStripMenuItem->Size = System::Drawing::Size(122, 26);
			this->wavToolStripMenuItem->Text = L"wav";
			// 
			// правкаToolStripMenuItem
			// 
			this->правкаToolStripMenuItem->Name = L"правкаToolStripMenuItem";
			this->правкаToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			this->правкаToolStripMenuItem->Text = L"Правка";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 162);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 7;
			// 
			// ClefsToolStrip
			// 
			this->ClefsToolStrip->AutoSize = false;
			this->ClefsToolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->ClefsToolStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->ClefsToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Clef1Button,
					this->Clef2Button
			});
			this->ClefsToolStrip->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->ClefsToolStrip->Location = System::Drawing::Point(8, 8);
			this->ClefsToolStrip->Name = L"ClefsToolStrip";
			this->ClefsToolStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->ClefsToolStrip->Size = System::Drawing::Size(136, 83);
			this->ClefsToolStrip->TabIndex = 8;
			this->ClefsToolStrip->Text = L"toolStrip2";
			// 
			// Clef1Button
			// 
			this->Clef1Button->AutoSize = false;
			this->Clef1Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Clef1Button->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->Clef1Button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Clef1Button.Image")));
			this->Clef1Button->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->Clef1Button->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Clef1Button->Name = L"Clef1Button";
			this->Clef1Button->Size = System::Drawing::Size(50, 70);
			this->Clef1Button->Text = L"toolStripButton13";
			// 
			// Clef2Button
			// 
			this->Clef2Button->AutoSize = false;
			this->Clef2Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Clef2Button->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->Clef2Button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Clef2Button.Image")));
			this->Clef2Button->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->Clef2Button->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Clef2Button->Name = L"Clef2Button";
			this->Clef2Button->Size = System::Drawing::Size(50, 70);
			this->Clef2Button->Text = L"toolStripButton14";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->NotesPictureBox);
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(38, 237);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1395, 480);
			this->flowLayoutPanel1->TabIndex = 10;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->CurrentNotePictureBox);
			this->panel1->Controls->Add(this->NotesToolStrip);
			this->panel1->Controls->Add(this->ClefsToolStrip);
			this->panel1->Location = System::Drawing::Point(16, 40);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1392, 112);
			this->panel1->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(1104, 24);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(256, 56);
			this->panel2->TabIndex = 13;
			// 
			// CurrentNotePictureBox
			// 
			this->CurrentNotePictureBox->Location = System::Drawing::Point(672, 8);
			this->CurrentNotePictureBox->Name = L"CurrentNotePictureBox";
			this->CurrentNotePictureBox->Size = System::Drawing::Size(104, 82);
			this->CurrentNotePictureBox->TabIndex = 12;
			this->CurrentNotePictureBox->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(304, 176);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(184, 48);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Parse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EditForm::button2_Click);
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 613);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->StreamTextBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"EditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EditForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &EditForm::EditForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &EditForm::EditForm_Load);
			this->NotesToolStrip->ResumeLayout(false);
			this->NotesToolStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NotesPictureBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ClefsToolStrip->ResumeLayout(false);
			this->ClefsToolStrip->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentNotePictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Check();
	toolStripButton6->Image = BMPFactory::GetNote(Duration::Double, Directions::Up);
	}
	private: System::Void Check() {
		System::Drawing::Font^ font = gcnew System::Drawing::Font("MusicM", 40);
		String^ str;
		for (int i = 1; i < 200; i++)
		{
			str += " " + Convert::ToChar(i) + i + " ";
		}
		StreamTextBox->Text += str;
		BMPFactory::DrawLines(NotesPictureBox, 100);
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
