#pragma once
#include "MIDIParser.h"
#include "BMPFactory.h"
#include "NoteParser.h"
#include "MIDIWriter.h"
#include "FormatConverter.h"

namespace MIDINoteEditor {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

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
			PictureBoxHeight = 180;
			CenterLineVerticalOffset = 70;
			LineLength = PictureBoxWidth;
			PictureBoxNumber = 0;
			DrawPoses = false;
			CurrentAcc = 0;
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
		bool DrawPoses;
		List<NormalNote^>^ CurrPos;

	private: System::Windows::Forms::ToolStrip^ NotesToolStrip;

	private:
		int PictureBoxWidth;
		int PictureBoxHeight;
		int CenterLineVerticalOffset;
		int PositionWidth;
		int PositionHeight;
		int HalfLineWidth;
		int LineLength;
		int PictureBoxNumber;
	private:
		int CurrentClef;
		int CurrentDuration;
		int CurrentAcc;
		int CurrentTempo;
		int CurrentNum;
		int CurrentDenum;
		double CurrentNoteDur;
		SoundPlayer^ Player;
	private:
		Dictionary<String^, int>^ NoteToHeight;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ правкаToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^ DoubleButton;
	private: System::Windows::Forms::ToolStripButton^ WholeButton;
	private: System::Windows::Forms::ToolStripButton^ HalfButton;
	private: System::Windows::Forms::ToolStripButton^ QuarterButton;
	private: System::Windows::Forms::ToolStripButton^ EightsButton;
	private: System::Windows::Forms::ToolStripButton^ SixteensButton;
	private: System::Windows::Forms::ToolStripButton^ ThirtyTwosButton;

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

	private: System::Windows::Forms::Button^ PlayButton;
	private: System::Windows::Forms::Button^ RestartButton;


	private: System::Windows::Forms::Button^ Pausebutton;



	private: System::Windows::Forms::Label^ positionLabel;
	private: System::Windows::Forms::CheckBox^ ShowPosCheckBox;
	private: System::Windows::Forms::Label^ label1;


private: System::Windows::Forms::ToolStripMenuItem^ вперёдToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^ назадToolStripMenuItem;
private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
private: System::Windows::Forms::Label^ label2;

private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::DomainUpDown^ domainUpDown2;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::Button^ BemolButton;
private: System::Windows::Forms::Button^ DiezButton;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Button^ DeleteButton;



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
			this->WholeButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->DoubleButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->HalfButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->QuarterButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->EightsButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->SixteensButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ThirtyTwosButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->midiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mp3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wavToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вперёдToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->назадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ClefsToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->Clef1Button = (gcnew System::Windows::Forms::ToolStripButton());
			this->Clef2Button = (gcnew System::Windows::Forms::ToolStripButton());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->DiezButton = (gcnew System::Windows::Forms::Button());
			this->BemolButton = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->domainUpDown2 = (gcnew System::Windows::Forms::DomainUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ShowPosCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->playerPanel = (gcnew System::Windows::Forms::Panel());
			this->RestartButton = (gcnew System::Windows::Forms::Button());
			this->Pausebutton = (gcnew System::Windows::Forms::Button());
			this->PlayButton = (gcnew System::Windows::Forms::Button());
			this->CurrentNotePictureBox = (gcnew System::Windows::Forms::PictureBox());
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
			this->NotesToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->WholeButton,
					this->DoubleButton, this->HalfButton, this->QuarterButton, this->EightsButton, this->SixteensButton, this->ThirtyTwosButton
			});
			this->NotesToolStrip->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->NotesToolStrip->Location = System::Drawing::Point(110, 21);
			this->NotesToolStrip->Name = L"NotesToolStrip";
			this->NotesToolStrip->Size = System::Drawing::Size(340, 65);
			this->NotesToolStrip->TabIndex = 3;
			this->NotesToolStrip->Text = L"w";
			// 
			// WholeButton
			// 
			this->WholeButton->AutoSize = false;
			this->WholeButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->WholeButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->WholeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"WholeButton.Image")));
			this->WholeButton->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->WholeButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->WholeButton->Name = L"WholeButton";
			this->WholeButton->Size = System::Drawing::Size(48, 63);
			this->WholeButton->Text = L"WholeButton";
			this->WholeButton->Click += gcnew System::EventHandler(this, &EditForm::WholeButton_Click);
			// 
			// DoubleButton
			// 
			this->DoubleButton->AutoSize = false;
			this->DoubleButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->DoubleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->DoubleButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DoubleButton.Image")));
			this->DoubleButton->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->DoubleButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->DoubleButton->Name = L"DoubleButton";
			this->DoubleButton->Size = System::Drawing::Size(48, 63);
			this->DoubleButton->Text = L"DoubleButton";
			this->DoubleButton->Click += gcnew System::EventHandler(this, &EditForm::DoubleButton_Click);
			// 
			// HalfButton
			// 
			this->HalfButton->AutoSize = false;
			this->HalfButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->HalfButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->HalfButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"HalfButton.Image")));
			this->HalfButton->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->HalfButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->HalfButton->Name = L"HalfButton";
			this->HalfButton->Size = System::Drawing::Size(48, 63);
			this->HalfButton->Text = L"HalfButton";
			this->HalfButton->Click += gcnew System::EventHandler(this, &EditForm::HalfButton_Click);
			// 
			// QuarterButton
			// 
			this->QuarterButton->AutoSize = false;
			this->QuarterButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->QuarterButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->QuarterButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QuarterButton.Image")));
			this->QuarterButton->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->QuarterButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->QuarterButton->Name = L"QuarterButton";
			this->QuarterButton->Size = System::Drawing::Size(48, 63);
			this->QuarterButton->Text = L"EightsButton";
			this->QuarterButton->Click += gcnew System::EventHandler(this, &EditForm::QuarterButton_Click);
			// 
			// EightsButton
			// 
			this->EightsButton->AutoSize = false;
			this->EightsButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->EightsButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->EightsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EightsButton.Image")));
			this->EightsButton->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->EightsButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->EightsButton->Name = L"EightsButton";
			this->EightsButton->Size = System::Drawing::Size(48, 63);
			this->EightsButton->Text = L"QuarterButton";
			this->EightsButton->Click += gcnew System::EventHandler(this, &EditForm::EightsButton_Click);
			// 
			// SixteensButton
			// 
			this->SixteensButton->AutoSize = false;
			this->SixteensButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->SixteensButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->SixteensButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 40));
			this->SixteensButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SixteensButton.Image")));
			this->SixteensButton->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->SixteensButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->SixteensButton->Margin = System::Windows::Forms::Padding(1);
			this->SixteensButton->Name = L"SixteensButton";
			this->SixteensButton->Size = System::Drawing::Size(48, 63);
			this->SixteensButton->Text = L"SixteensButton";
			this->SixteensButton->Click += gcnew System::EventHandler(this, &EditForm::SixteensButton_Click);
			// 
			// ThirtyTwosButton
			// 
			this->ThirtyTwosButton->AutoSize = false;
			this->ThirtyTwosButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ThirtyTwosButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->ThirtyTwosButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ThirtyTwosButton.Image")));
			this->ThirtyTwosButton->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->ThirtyTwosButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ThirtyTwosButton->Name = L"ThirtyTwosButton";
			this->ThirtyTwosButton->Size = System::Drawing::Size(48, 63);
			this->ThirtyTwosButton->Text = L"ThirtyTwosButton";
			this->ThirtyTwosButton->Click += gcnew System::EventHandler(this, &EditForm::ThirtyTwosButton_Click);
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
			this->midiToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm::midiToolStripMenuItem_Click);
			// 
			// mp3ToolStripMenuItem
			// 
			this->mp3ToolStripMenuItem->Name = L"mp3ToolStripMenuItem";
			this->mp3ToolStripMenuItem->Size = System::Drawing::Size(108, 24);
			this->mp3ToolStripMenuItem->Text = L"mp3";
			this->mp3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm::mp3ToolStripMenuItem_Click);
			// 
			// wavToolStripMenuItem
			// 
			this->wavToolStripMenuItem->Name = L"wavToolStripMenuItem";
			this->wavToolStripMenuItem->Size = System::Drawing::Size(108, 24);
			this->wavToolStripMenuItem->Text = L"wav";
			this->wavToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm::wavToolStripMenuItem_Click);
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
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(79, 24);
			this->справкаToolStripMenuItem->Text = L"Справка";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm::справкаToolStripMenuItem_Click);
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
			this->ClefsToolStrip->Size = System::Drawing::Size(101, 65);
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
			this->Clef1Button->Size = System::Drawing::Size(50, 65);
			this->Clef1Button->Text = L"toolStripButton13";
			this->Clef1Button->Click += gcnew System::EventHandler(this, &EditForm::Clef1Button_Click);
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
			this->Clef2Button->Size = System::Drawing::Size(50, 65);
			this->Clef2Button->Text = L"toolStripButton14";
			this->Clef2Button->Click += gcnew System::EventHandler(this, &EditForm::Clef2Button_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::White;
			this->flowLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 207);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1088, 336);
			this->flowLayoutPanel1->TabIndex = 10;
			this->flowLayoutPanel1->WrapContents = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->DeleteButton);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->DiezButton);
			this->panel1->Controls->Add(this->BemolButton);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->numericUpDown4);
			this->panel1->Controls->Add(this->numericUpDown3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->domainUpDown2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->numericUpDown2);
			this->panel1->Controls->Add(this->numericUpDown1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->ShowPosCheckBox);
			this->panel1->Controls->Add(this->positionLabel);
			this->panel1->Controls->Add(this->playerPanel);
			this->panel1->Controls->Add(this->CurrentNotePictureBox);
			this->panel1->Controls->Add(this->NotesToolStrip);
			this->panel1->Controls->Add(this->ClefsToolStrip);
			this->panel1->Location = System::Drawing::Point(12, 32);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1088, 171);
			this->panel1->TabIndex = 11;
			// 
			// DeleteButton
			// 
			this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeleteButton->Location = System::Drawing::Point(938, 125);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(96, 35);
			this->DeleteButton->TabIndex = 34;
			this->DeleteButton->Text = L"Удалить";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &EditForm::DeleteButton_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(938, 79);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(96, 35);
			this->button5->TabIndex = 33;
			this->button5->Text = L"Добавить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &EditForm::button5_Click);
			// 
			// DiezButton
			// 
			this->DiezButton->BackColor = System::Drawing::SystemColors::Menu;
			this->DiezButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->DiezButton->FlatAppearance->BorderSize = 0;
			this->DiezButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->DiezButton->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->DiezButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DiezButton->Location = System::Drawing::Point(456, 21);
			this->DiezButton->Margin = System::Windows::Forms::Padding(0);
			this->DiezButton->Name = L"DiezButton";
			this->DiezButton->Size = System::Drawing::Size(30, 32);
			this->DiezButton->TabIndex = 32;
			this->DiezButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->DiezButton->UseVisualStyleBackColor = false;
			this->DiezButton->Click += gcnew System::EventHandler(this, &EditForm::DiezButton_Click);
			// 
			// BemolButton
			// 
			this->BemolButton->BackColor = System::Drawing::SystemColors::Menu;
			this->BemolButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->BemolButton->FlatAppearance->BorderSize = 0;
			this->BemolButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BemolButton->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BemolButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BemolButton->Location = System::Drawing::Point(456, 54);
			this->BemolButton->Name = L"BemolButton";
			this->BemolButton->Size = System::Drawing::Size(30, 32);
			this->BemolButton->TabIndex = 31;
			this->BemolButton->UseVisualStyleBackColor = false;
			this->BemolButton->Click += gcnew System::EventHandler(this, &EditForm::BemolButton_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(161, 129);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(148, 27);
			this->button4->TabIndex = 29;
			this->button4->Text = L"Удалить ноту";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &EditForm::button4_Click);
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
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &EditForm::numericUpDown4_ValueChanged);
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
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &EditForm::numericUpDown3_ValueChanged);
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
			this->button3->Location = System::Drawing::Point(17, 129);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(138, 27);
			this->button3->TabIndex = 25;
			this->button3->Text = L"Добавить ноту";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &EditForm::button3_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(600, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 35);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Очистить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditForm::button1_Click);
			// 
			// domainUpDown2
			// 
			this->domainUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDown2->Location = System::Drawing::Point(207, 96);
			this->domainUpDown2->Name = L"domainUpDown2";
			this->domainUpDown2->Size = System::Drawing::Size(135, 26);
			this->domainUpDown2->TabIndex = 23;
			this->domainUpDown2->Text = L"C3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(13, 98);
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
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &EditForm::numericUpDown2_ValueChanged);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(673, 79);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(55, 26);
			this->numericUpDown1->TabIndex = 19;
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
			this->ShowPosCheckBox->Location = System::Drawing::Point(349, 132);
			this->ShowPosCheckBox->Name = L"ShowPosCheckBox";
			this->ShowPosCheckBox->Size = System::Drawing::Size(189, 24);
			this->ShowPosCheckBox->TabIndex = 17;
			this->ShowPosCheckBox->Text = L"Отображать позиции";
			this->ShowPosCheckBox->UseVisualStyleBackColor = true;
			this->ShowPosCheckBox->CheckedChanged += gcnew System::EventHandler(this, &EditForm::ShowPosCheckBox_CheckedChanged);
			// 
			// positionLabel
			// 
			this->positionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->positionLabel->Location = System::Drawing::Point(659, 0);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(87, 67);
			this->positionLabel->TabIndex = 16;
			this->positionLabel->Text = L"Текущая позиция:";
			this->positionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->PlayButton->Click += gcnew System::EventHandler(this, &EditForm::PlayButton_Click);
			// 
			// CurrentNotePictureBox
			// 
			this->CurrentNotePictureBox->BackColor = System::Drawing::Color::White;
			this->CurrentNotePictureBox->Location = System::Drawing::Point(751, 5);
			this->CurrentNotePictureBox->Margin = System::Windows::Forms::Padding(2);
			this->CurrentNotePictureBox->Name = L"CurrentNotePictureBox";
			this->CurrentNotePictureBox->Size = System::Drawing::Size(133, 162);
			this->CurrentNotePictureBox->TabIndex = 12;
			this->CurrentNotePictureBox->TabStop = false;
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1106, 544);
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
	private:  System::Void EditForm::DrawClefs();
	private:  System::Void EditForm::DrawDurations();
	private:  System::Void EditForm::DrawAccidentals();
	System::Void initializeRowsUpDown(DomainUpDown^ rowsUpDown);
	System::Void initializeNotesUpDown(DomainUpDown^ rowsUpDown);
	ClefToDraw^ EditForm::RecognizeClef(List<NormalNote^>^ currentPosition);
	bool EditForm::ClefChanged(ClefToDraw^ curClef, List<NormalNote^>^ currentPosition);
	PictureBox^ EditForm::CreateAddPictureBox();

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ShowPosCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ShowPosCheckBox->Checked){
		DrawPoses = true;
		flowLayoutPanel1->Controls->Clear();
		DrawTrack();
	}
	else {
		DrawPoses = false;
		flowLayoutPanel1->Controls->Clear();
		DrawTrack();
	}
		
}
private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ info = "Стартовое окно приложения:\n\n" + "Файл - найти файл, чтобы открыть.\n" + "Логи - информация о процессе анализа файла.\n"
		+ "Настройки - чтобы выбрать директорию по умолчанию и Soundfont.\n" + "Справка - краткие пояснения к интерфейсу.\n"
		+ "О разработчике - информация о создателе.\n\n" + "Создать файл - создание пустого файла.\n" + "Открыть файл - выбор существующего.\n"
		+ "Открыть проигрыватель - открыть окно для воспроизведения.";
	MessageBox::Show(info, "Справка", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	private: System::Void midiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = " MIDI|*.mid";
		saveFileDialog1->Title = "Save MIDI file";
		if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
			if (saveFileDialog1->FileName != "") {
				String^ fileName = saveFileDialog1->FileName;
				try {
					MIDIWriter^ midiWriter = gcnew MIDIWriter(noteParser, fileName);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Ошибка записи в файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else
				MessageBox::Show("Некорректный файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}		
	}
private: System::Void mp3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = " MP3|*.mp3";
	saveFileDialog1->Title = "Save MP3 file";
	saveFileDialog1->InitialDirectory = GetSettings()[1];
	String^ tempFileName = Directory::GetCurrentDirectory() + "\\Tracks\\temp.mid";
	if (File::Exists(tempFileName))
	{
		File::Delete(tempFileName);
	}
	if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		if (saveFileDialog1->FileName != "") {
			String^ fileName = saveFileDialog1->FileName;
			try {
				MIDIWriter^ midiWriter = gcnew MIDIWriter(noteParser, tempFileName);
				FormatConverter::ConvertMIDI("MP3", tempFileName, fileName, GetSettings()[0]);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка записи в файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
			MessageBox::Show("Некорректный файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	if (File::Exists(tempFileName))
	{
		File::Delete(tempFileName);
	}
}
private: System::Void wavToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = " Wav|*.wav";
	saveFileDialog1->Title = "Save wav file";
	String^ tempFileName = Directory::GetCurrentDirectory() + "\\Tracks\\temp.mid";
	if (File::Exists(tempFileName))
	{
		File::Delete(tempFileName);
	}
	if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		if (saveFileDialog1->FileName != "") {
			String^ fileName = saveFileDialog1->FileName;
			try {
				MIDIWriter^ midiWriter = gcnew MIDIWriter(noteParser, tempFileName);
				FormatConverter::ConvertMIDI("WAV", tempFileName, fileName, GetSettings()[0]);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка записи в файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
			MessageBox::Show("Некорректный файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	if (File::Exists(tempFileName))
	{
		File::Delete(tempFileName);
	}
}

	   private: void IncrementIndexes(int startIndex) {
		   NormalNote^ currNote;
		   for (int i = startIndex; i < noteParser->NoteLines[0]->Notes->Count; i++) {
			   currNote = noteParser->NoteLines[0]->Notes[i];
			   currNote->TrackPosition++;
		   }
	   }

			private: void DecrementIndexes(int startIndex) {
				  NormalNote^ currNote;
				  for (int i = startIndex; i < noteParser->NoteLines[0]->Notes->Count; i++) {
					  currNote = noteParser->NoteLines[0]->Notes[i];
					  currNote->TrackPosition--;
				  }
			  }

	private: UInt32 GetIndexByPosNum(UInt32 posNum) {
		UInt32 index = -1;
		NormalNote^ currNote;
		for (int i = 0; i < noteParser->NoteLines[0]->Notes->Count; i++) {
			currNote = noteParser->NoteLines[0]->Notes[i];
			if (currNote->TrackPosition == posNum) {
				index = i;
				return index;
			}
		}
		return index;
	}

private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	NormalNote^ currNote;
	bool isEnd = false;
	NormalNote^ prevNote;
	String^ text = numericUpDown1->Text;
	Int32 numToDelete = Convert::ToInt32(text);
	Int32 realIndex = GetIndexByPosNum(numToDelete);
	UInt32 count = 1;
	if (realIndex != -1) {
		prevNote = noteParser->NoteLines[0]->Notes[realIndex];
		for (int i = realIndex + 1; (i < noteParser->NoteLines[0]->Notes->Count) && (!isEnd); i++) {
			currNote = noteParser->NoteLines[0]->Notes[i];
			if (prevNote->TrackPosition == currNote->TrackPosition)
				count++;
			else
				isEnd = true;
		}
		noteParser->NoteLines[0]->Notes->RemoveRange(realIndex, count);
		DecrementIndexes(realIndex);
	}
	DrawTrack();
}
	   /*
	private: List<NormalNote^>^ GetCurrentNotePosition() {
		UInt32 index = -1;
		NormalNote^ currNote;
		for (int i = 0; i < noteParser->NoteLines[0]->Notes->Count; i++) {
			currNote = noteParser->NoteLines[0]->Notes[i];
			if (currNote->TrackPosition == posNum) {
				index = i;
				return index;
			}
		}
		return index;
	}
	*/
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Clef1Button_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentClef = (int)Clefs::Treble;
}
private: System::Void Clef2Button_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentClef = (int)Clefs::Bas;
}
private: System::Void DoubleButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentNoteDur = 2.0;
}
private: System::Void HalfButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentNoteDur = 0.5;
}
	   System::Void EditForm::initializeDictionary();
private: System::Void WholeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentNoteDur = 1.0;
}
private: System::Void QuarterButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentNoteDur = 0.25;
}
private: System::Void EightsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentNoteDur = 0.125;
}
private: System::Void SixteensButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentNoteDur = 0.0625;
}
private: System::Void ThirtyTwosButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentNoteDur = 0.03125;
}
private: System::Void numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	CurrentNum = Convert::ToInt32(numericUpDown3->Value);
}
private: System::Void numericUpDown4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	CurrentDenum = Convert::ToInt32(numericUpDown4->Value);
}
private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	CurrentTempo = Convert::ToInt32(numericUpDown2->Value);
}

	   void EditForm::DrawNote();
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	NormalNote^ currNote = gcnew NormalNote();
	String^ currNoteName = domainUpDown2->Text;
	currNote->Height = NoteToHeight[currNoteName] + CurrentAcc;
	CurrentAcc = 0;
	currNote->TrackPosition = Convert::ToInt32(numericUpDown1->Value);
	currNote->Length = CurrentNoteDur;
	currNote->setTempo->TPQ = CurrentTempo;
	currNote->timeSignature->Numerator = CurrentNum;
	currNote->timeSignature->Denumerator = CurrentDenum;
	currNote->Velocity = 80;
	CurrPos->Add(currNote);
	DrawNote();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (CurrPos->Count > 0) {
		CurrPos->RemoveAt(CurrPos->Count - 1);
		DrawNote();
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrPos->RemoveRange(0, CurrPos->Count);
}
private: System::Void DiezButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentAcc = 1;
}
private: System::Void BemolButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CurrentAcc = -1;
}
private: System::Void PlayButton_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
	List<String^>^ settings = GetSettings();
	fileDialog->InitialDirectory = Directory::GetCurrentDirectory() + "\\Tracks\\";
	fileDialog->Filter = "all files(*)|*.*|mid file (*mid)|*.mid|wav file (*wav)|*.wav";
	String^ fileName = Directory::GetCurrentDirectory() + "\\Tracks\\temp.mid";
	String^ tempFileName = Directory::GetCurrentDirectory() + "\\Tracks\\temp.wav";
	if (File::Exists(tempFileName))
	{
		File::Delete(tempFileName);
	}

	try {
		FormatConverter::ConvertMIDI("WAV", fileName, tempFileName, settings[0]);
		System::Threading::Thread::Sleep(2000);
		Player = gcnew SoundPlayer(tempFileName);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Некорректный файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
