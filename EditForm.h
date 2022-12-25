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
			HalfLineWidth = 7;
			PictureBoxHeight = 140;
			CenterLineVerticalOffset = 50;
			PictureBoxWidth = 600;
			LineLength = PictureBoxWidth;
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


	private: System::Windows::Forms::ToolStrip^ NotesToolStrip;



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
	private:
		int PictureBoxWidth;
		int PictureBoxHeight;
		int CenterLineVerticalOffset;
		int PositionWidth;
		int PositionHeight;
		int HalfLineWidth;
		int LineLength;
	private:
		int CurrentClef;
		int CurrentDuration;
		int CurrentAcc;
		int CurrentTempo;
		int CurrentNum;
		int CurrentDenum;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ правкаToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;




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
	private: System::Windows::Forms::Panel^ playerPanel;

	private: System::Windows::Forms::ToolStripMenuItem^ midiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mp3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ wavToolStripMenuItem;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ PlayButton;
	private: System::Windows::Forms::Button^ RestartButton;


	private: System::Windows::Forms::Button^ Pausebutton;

	private: System::Windows::Forms::RadioButton^ AddRadioButton;
	private: System::Windows::Forms::RadioButton^ DeleteRadioButton;
	private: System::Windows::Forms::Label^ positionLabel;
	private: System::Windows::Forms::CheckBox^ ShowPosCheckBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton13;
	private: System::Windows::Forms::ToolStripMenuItem^ вперёдToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ вперёдToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^ назадToolStripMenuItem;
private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::DomainUpDown^ domainUpDown1;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::DomainUpDown^ domainUpDown2;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
private: System::Windows::Forms::Button^ button4;



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
			this->toolStripButton13 = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->midiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mp3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wavToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вперёдToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->назадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вперёдToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ClefsToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->Clef1Button = (gcnew System::Windows::Forms::ToolStripButton());
			this->Clef2Button = (gcnew System::Windows::Forms::ToolStripButton());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->domainUpDown2 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ShowPosCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->DeleteRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->AddRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->playerPanel = (gcnew System::Windows::Forms::Panel());
			this->RestartButton = (gcnew System::Windows::Forms::Button());
			this->Pausebutton = (gcnew System::Windows::Forms::Button());
			this->PlayButton = (gcnew System::Windows::Forms::Button());
			this->CurrentNotePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->NotesToolStrip->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->ClefsToolStrip->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->playerPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentNotePictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// NotesToolStrip
			// 
			this->NotesToolStrip->AutoSize = false;
			this->NotesToolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->NotesToolStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->NotesToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {
				this->toolStripButton1,
					this->toolStripButton3, this->toolStripButton2, this->toolStripButton5, this->toolStripButton4, this->toolStripButton6, this->toolStripButton7,
					this->toolStripButton11, this->toolStripButton10, this->toolStripButton9, this->toolStripButton8, this->toolStripButton12, this->toolStripButton13
			});
			this->NotesToolStrip->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->NotesToolStrip->Location = System::Drawing::Point(110, 26);
			this->NotesToolStrip->Name = L"NotesToolStrip";
			this->NotesToolStrip->Size = System::Drawing::Size(318, 54);
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
			// toolStripButton13
			// 
			this->toolStripButton13->AutoSize = false;
			this->toolStripButton13->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 40));
			this->toolStripButton13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton13.Image")));
			this->toolStripButton13->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton13->Margin = System::Windows::Forms::Padding(1);
			this->toolStripButton13->Name = L"toolStripButton13";
			this->toolStripButton13->Size = System::Drawing::Size(40, 40);
			this->toolStripButton13->Text = L"toolStripButton6";
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1106, 28);
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
			this->файлToolStripMenuItem->Size = System::Drawing::Size(95, 24);
			this->файлToolStripMenuItem->Text = L"Сохранить";
			// 
			// midiToolStripMenuItem
			// 
			this->midiToolStripMenuItem->Name = L"midiToolStripMenuItem";
			this->midiToolStripMenuItem->Size = System::Drawing::Size(108, 24);
			this->midiToolStripMenuItem->Text = L"midi";
			// 
			// mp3ToolStripMenuItem
			// 
			this->mp3ToolStripMenuItem->Name = L"mp3ToolStripMenuItem";
			this->mp3ToolStripMenuItem->Size = System::Drawing::Size(108, 24);
			this->mp3ToolStripMenuItem->Text = L"mp3";
			// 
			// wavToolStripMenuItem
			// 
			this->wavToolStripMenuItem->Name = L"wavToolStripMenuItem";
			this->wavToolStripMenuItem->Size = System::Drawing::Size(108, 24);
			this->wavToolStripMenuItem->Text = L"wav";
			// 
			// правкаToolStripMenuItem
			// 
			this->правкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->вперёдToolStripMenuItem1,
					this->назадToolStripMenuItem
			});
			this->правкаToolStripMenuItem->Name = L"правкаToolStripMenuItem";
			this->правкаToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->правкаToolStripMenuItem->Text = L"Правка";
			// 
			// вперёдToolStripMenuItem1
			// 
			this->вперёдToolStripMenuItem1->Name = L"вперёдToolStripMenuItem1";
			this->вперёдToolStripMenuItem1->Size = System::Drawing::Size(129, 24);
			this->вперёдToolStripMenuItem1->Text = L"Вперёд";
			// 
			// назадToolStripMenuItem
			// 
			this->назадToolStripMenuItem->Name = L"назадToolStripMenuItem";
			this->назадToolStripMenuItem->Size = System::Drawing::Size(129, 24);
			this->назадToolStripMenuItem->Text = L"Назад";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->вперёдToolStripMenuItem });
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(79, 24);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// вперёдToolStripMenuItem
			// 
			this->вперёдToolStripMenuItem->Name = L"вперёдToolStripMenuItem";
			this->вперёдToolStripMenuItem->Size = System::Drawing::Size(129, 24);
			this->вперёдToolStripMenuItem->Text = L"Вперёд";
			// 
			// ClefsToolStrip
			// 
			this->ClefsToolStrip->AutoSize = false;
			this->ClefsToolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->ClefsToolStrip->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->ClefsToolStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->ClefsToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Clef1Button,
					this->Clef2Button
			});
			this->ClefsToolStrip->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->ClefsToolStrip->Location = System::Drawing::Point(3, 21);
			this->ClefsToolStrip->Name = L"ClefsToolStrip";
			this->ClefsToolStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->ClefsToolStrip->Size = System::Drawing::Size(102, 62);
			this->ClefsToolStrip->TabIndex = 8;
			this->ClefsToolStrip->Text = L"toolStrip2";
			// 
			// Clef1Button
			// 
			this->Clef1Button->AutoSize = false;
			this->Clef1Button->BackColor = System::Drawing::SystemColors::Menu;
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
			this->Clef2Button->BackColor = System::Drawing::SystemColors::Menu;
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
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::White;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 188);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1088, 290);
			this->flowLayoutPanel1->TabIndex = 10;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->numericUpDown4);
			this->panel1->Controls->Add(this->numericUpDown3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->domainUpDown2);
			this->panel1->Controls->Add(this->domainUpDown1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->numericUpDown2);
			this->panel1->Controls->Add(this->numericUpDown1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->ShowPosCheckBox);
			this->panel1->Controls->Add(this->positionLabel);
			this->panel1->Controls->Add(this->DeleteRadioButton);
			this->panel1->Controls->Add(this->AddRadioButton);
			this->panel1->Controls->Add(this->playerPanel);
			this->panel1->Controls->Add(this->CurrentNotePictureBox);
			this->panel1->Controls->Add(this->NotesToolStrip);
			this->panel1->Controls->Add(this->ClefsToolStrip);
			this->panel1->Location = System::Drawing::Point(12, 32);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1088, 152);
			this->panel1->TabIndex = 11;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown4->Location = System::Drawing::Point(499, 66);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->numericUpDown4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(39, 26);
			this->numericUpDown4->TabIndex = 28;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown3->Location = System::Drawing::Point(499, 21);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(39, 26);
			this->numericUpDown3->TabIndex = 27;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->Location = System::Drawing::Point(499, 55);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(39, 3);
			this->panel2->TabIndex = 26;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(430, 122);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 27);
			this->button3->TabIndex = 25;
			this->button3->Text = L"Добавить";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(667, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 35);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Очистить";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// domainUpDown2
			// 
			this->domainUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDown2->Location = System::Drawing::Point(375, 96);
			this->domainUpDown2->Name = L"domainUpDown2";
			this->domainUpDown2->Size = System::Drawing::Size(135, 26);
			this->domainUpDown2->TabIndex = 23;
			this->domainUpDown2->Text = L"Выберите ноту";
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDown1->Location = System::Drawing::Point(197, 96);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->Size = System::Drawing::Size(172, 26);
			this->domainUpDown1->TabIndex = 22;
			this->domainUpDown1->Text = L"Выберите линейку";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(188, 20);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Выберите высоту ноты:";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown2->Location = System::Drawing::Point(573, 79);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(55, 26);
			this->numericUpDown2->TabIndex = 20;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 120, 0, 0, 0 });
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(691, 79);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(55, 26);
			this->numericUpDown1->TabIndex = 19;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(914, 69);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(138, 39);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Parse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EditForm::button2_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(534, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 68);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Скорость воспроизвдения(BPM):";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ShowPosCheckBox
			// 
			this->ShowPosCheckBox->AutoSize = true;
			this->ShowPosCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ShowPosCheckBox->Location = System::Drawing::Point(235, 124);
			this->ShowPosCheckBox->Name = L"ShowPosCheckBox";
			this->ShowPosCheckBox->Size = System::Drawing::Size(189, 24);
			this->ShowPosCheckBox->TabIndex = 17;
			this->ShowPosCheckBox->Text = L"Отображать позиции";
			this->ShowPosCheckBox->UseVisualStyleBackColor = true;
			// 
			// positionLabel
			// 
			this->positionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->positionLabel->Location = System::Drawing::Point(663, 9);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(110, 67);
			this->positionLabel->TabIndex = 16;
			this->positionLabel->Text = L"Текущая позиция:";
			this->positionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DeleteRadioButton
			// 
			this->DeleteRadioButton->AutoSize = true;
			this->DeleteRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeleteRadioButton->Location = System::Drawing::Point(126, 123);
			this->DeleteRadioButton->Name = L"DeleteRadioButton";
			this->DeleteRadioButton->Size = System::Drawing::Size(103, 24);
			this->DeleteRadioButton->TabIndex = 15;
			this->DeleteRadioButton->TabStop = true;
			this->DeleteRadioButton->Text = L"Удаление";
			this->DeleteRadioButton->UseVisualStyleBackColor = true;
			// 
			// AddRadioButton
			// 
			this->AddRadioButton->AutoSize = true;
			this->AddRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddRadioButton->Location = System::Drawing::Point(3, 123);
			this->AddRadioButton->Name = L"AddRadioButton";
			this->AddRadioButton->Size = System::Drawing::Size(121, 24);
			this->AddRadioButton->TabIndex = 14;
			this->AddRadioButton->TabStop = true;
			this->AddRadioButton->Text = L"Добавление";
			this->AddRadioButton->UseVisualStyleBackColor = true;
			// 
			// playerPanel
			// 
			this->playerPanel->Controls->Add(this->RestartButton);
			this->playerPanel->Controls->Add(this->Pausebutton);
			this->playerPanel->Controls->Add(this->PlayButton);
			this->playerPanel->Location = System::Drawing::Point(888, 4);
			this->playerPanel->Margin = System::Windows::Forms::Padding(2);
			this->playerPanel->Name = L"playerPanel";
			this->playerPanel->Size = System::Drawing::Size(192, 61);
			this->playerPanel->TabIndex = 13;
			// 
			// RestartButton
			// 
			this->RestartButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->RestartButton->FlatAppearance->BorderSize = 0;
			this->RestartButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RestartButton->Location = System::Drawing::Point(128, 4);
			this->RestartButton->Margin = System::Windows::Forms::Padding(2);
			this->RestartButton->Name = L"RestartButton";
			this->RestartButton->Size = System::Drawing::Size(56, 52);
			this->RestartButton->TabIndex = 16;
			this->RestartButton->UseVisualStyleBackColor = true;
			// 
			// Pausebutton
			// 
			this->Pausebutton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Pausebutton->FlatAppearance->BorderSize = 0;
			this->Pausebutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Pausebutton->Location = System::Drawing::Point(68, 4);
			this->Pausebutton->Margin = System::Windows::Forms::Padding(2);
			this->Pausebutton->Name = L"Pausebutton";
			this->Pausebutton->Size = System::Drawing::Size(56, 52);
			this->Pausebutton->TabIndex = 15;
			this->Pausebutton->UseVisualStyleBackColor = true;
			// 
			// PlayButton
			// 
			this->PlayButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->PlayButton->FlatAppearance->BorderSize = 0;
			this->PlayButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PlayButton->Location = System::Drawing::Point(3, 4);
			this->PlayButton->Margin = System::Windows::Forms::Padding(2);
			this->PlayButton->Name = L"PlayButton";
			this->PlayButton->Size = System::Drawing::Size(56, 52);
			this->PlayButton->TabIndex = 14;
			this->PlayButton->UseVisualStyleBackColor = true;
			// 
			// CurrentNotePictureBox
			// 
			this->CurrentNotePictureBox->BackColor = System::Drawing::Color::White;
			this->CurrentNotePictureBox->Location = System::Drawing::Point(768, 5);
			this->CurrentNotePictureBox->Margin = System::Windows::Forms::Padding(2);
			this->CurrentNotePictureBox->Name = L"CurrentNotePictureBox";
			this->CurrentNotePictureBox->Size = System::Drawing::Size(107, 142);
			this->CurrentNotePictureBox->TabIndex = 12;
			this->CurrentNotePictureBox->TabStop = false;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(544, 122);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(108, 27);
			this->button4->TabIndex = 29;
			this->button4->Text = L"Удалить";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1106, 480);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"EditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EditForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &EditForm::EditForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &EditForm::EditForm_Load);
			this->NotesToolStrip->ResumeLayout(false);
			this->NotesToolStrip->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ClefsToolStrip->ResumeLayout(false);
			this->ClefsToolStrip->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->playerPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentNotePictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private:  System::Void EditForm::DrawTrack();
	private:  System::Void EditForm::DrawPosition();
	private:  System::Void EditForm::DrawClefs();
	private:  System::Void EditForm::DrawDurations();
	private:  System::Void EditForm::DrawAccidentals();
	System::Void initializeRowsUpDown(DomainUpDown^ rowsUpDown);
	System::Void initializeNotesUpDown(DomainUpDown^ rowsUpDown);
	int EditForm::RecognizeClef(int highest, int lowest);

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
