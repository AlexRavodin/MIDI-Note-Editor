#pragma once
#include "MIDIParser.h"
#include "BMPFactory.h"

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
	private: System::Windows::Forms::TextBox^ StreamTextBox;





	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;







	private: System::Windows::Forms::PictureBox^ NotePictureBox;
	public:

	public:

	public:

	public:
	private:



	protected:

	protected:

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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ правкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ воспроизведениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
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
	private: System::Windows::Forms::ToolStrip^ toolStrip2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton13;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton14;
	private: System::Windows::Forms::ToolStrip^ toolStrip3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton15;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton16;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton17;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton18;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton19;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton20;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton21;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton22;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton23;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton24;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton25;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton26;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
private: System::Windows::Forms::PictureBox^ pictureBox1;





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
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
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
			this->NotePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->воспроизведениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton13 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton14 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip3 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton15 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton16 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton17 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton18 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton19 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton20 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton21 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton22 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton23 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton24 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton25 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton26 = (gcnew System::Windows::Forms::ToolStripButton());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NotePictureBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->toolStrip2->SuspendLayout();
			this->toolStrip3->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// StreamTextBox
			// 
			this->StreamTextBox->Font = (gcnew System::Drawing::Font(L"MusicalSymbols", 20));
			this->StreamTextBox->Location = System::Drawing::Point(868, 37);
			this->StreamTextBox->Multiline = true;
			this->StreamTextBox->Name = L"StreamTextBox";
			this->StreamTextBox->Size = System::Drawing::Size(1244, 68);
			this->StreamTextBox->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1066, 115);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(276, 56);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditForm::button1_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->AutoSize = false;
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->toolStripButton1,
					this->toolStripButton3, this->toolStripButton2, this->toolStripButton5, this->toolStripButton4, this->toolStripButton6, this->toolStripButton7,
					this->toolStripButton11, this->toolStripButton10, this->toolStripButton9, this->toolStripButton8, this->toolStripButton12
			});
			this->toolStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->toolStrip1->Location = System::Drawing::Point(210, 37);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(246, 83);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
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
			// NotePictureBox
			// 
			this->NotePictureBox->Location = System::Drawing::Point(3, 3);
			this->NotePictureBox->Name = L"NotePictureBox";
			this->NotePictureBox->Size = System::Drawing::Size(1381, 129);
			this->NotePictureBox->TabIndex = 4;
			this->NotePictureBox->TabStop = false;
			this->NotePictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EditForm::pictureBox1_Paint);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->файлToolStripMenuItem,
					this->правкаToolStripMenuItem, this->воспроизведениеToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1482, 28);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// правкаToolStripMenuItem
			// 
			this->правкаToolStripMenuItem->Name = L"правкаToolStripMenuItem";
			this->правкаToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			this->правкаToolStripMenuItem->Text = L"Правка";
			// 
			// воспроизведениеToolStripMenuItem
			// 
			this->воспроизведениеToolStripMenuItem->Name = L"воспроизведениеToolStripMenuItem";
			this->воспроизведениеToolStripMenuItem->Size = System::Drawing::Size(149, 24);
			this->воспроизведениеToolStripMenuItem->Text = L"Воспроизведение";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(763, 82);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 96);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 162);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 7;
			// 
			// toolStrip2
			// 
			this->toolStrip2->AutoSize = false;
			this->toolStrip2->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton13,
					this->toolStripButton14
			});
			this->toolStrip2->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->toolStrip2->Location = System::Drawing::Point(93, 37);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(106, 83);
			this->toolStrip2->TabIndex = 8;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// toolStripButton13
			// 
			this->toolStripButton13->AutoSize = false;
			this->toolStripButton13->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton13.Image")));
			this->toolStripButton13->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton13->Name = L"toolStripButton13";
			this->toolStripButton13->Size = System::Drawing::Size(50, 70);
			this->toolStripButton13->Text = L"toolStripButton13";
			// 
			// toolStripButton14
			// 
			this->toolStripButton14->AutoSize = false;
			this->toolStripButton14->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton14.Image")));
			this->toolStripButton14->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton14->Name = L"toolStripButton14";
			this->toolStripButton14->Size = System::Drawing::Size(50, 70);
			this->toolStripButton14->Text = L"toolStripButton14";
			// 
			// toolStrip3
			// 
			this->toolStrip3->AutoSize = false;
			this->toolStrip3->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip3->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->toolStripButton15,
					this->toolStripButton16, this->toolStripButton17, this->toolStripButton18, this->toolStripButton19, this->toolStripButton20,
					this->toolStripButton21, this->toolStripButton22, this->toolStripButton23, this->toolStripButton24, this->toolStripButton25,
					this->toolStripButton26
			});
			this->toolStrip3->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->toolStrip3->Location = System::Drawing::Point(481, 37);
			this->toolStrip3->Name = L"toolStrip3";
			this->toolStrip3->Size = System::Drawing::Size(246, 83);
			this->toolStrip3->TabIndex = 9;
			this->toolStrip3->Text = L"toolStrip3";
			// 
			// toolStripButton15
			// 
			this->toolStripButton15->AutoSize = false;
			this->toolStripButton15->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton15.Image")));
			this->toolStripButton15->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton15->Name = L"toolStripButton15";
			this->toolStripButton15->Size = System::Drawing::Size(29, 24);
			this->toolStripButton15->Text = L"toolStripButton1";
			// 
			// toolStripButton16
			// 
			this->toolStripButton16->AutoSize = false;
			this->toolStripButton16->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton16.Image")));
			this->toolStripButton16->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton16->Name = L"toolStripButton16";
			this->toolStripButton16->Size = System::Drawing::Size(29, 24);
			this->toolStripButton16->Text = L"toolStripButton3";
			// 
			// toolStripButton17
			// 
			this->toolStripButton17->AutoSize = false;
			this->toolStripButton17->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton17.Image")));
			this->toolStripButton17->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton17->Name = L"toolStripButton17";
			this->toolStripButton17->Size = System::Drawing::Size(29, 24);
			this->toolStripButton17->Text = L"toolStripButton2";
			// 
			// toolStripButton18
			// 
			this->toolStripButton18->AutoSize = false;
			this->toolStripButton18->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton18.Image")));
			this->toolStripButton18->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton18->Name = L"toolStripButton18";
			this->toolStripButton18->Size = System::Drawing::Size(29, 24);
			this->toolStripButton18->Text = L"toolStripButton5";
			// 
			// toolStripButton19
			// 
			this->toolStripButton19->AutoSize = false;
			this->toolStripButton19->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton19.Image")));
			this->toolStripButton19->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton19->Name = L"toolStripButton19";
			this->toolStripButton19->Size = System::Drawing::Size(29, 24);
			this->toolStripButton19->Text = L"toolStripButton4";
			// 
			// toolStripButton20
			// 
			this->toolStripButton20->AutoSize = false;
			this->toolStripButton20->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 40));
			this->toolStripButton20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton20.Image")));
			this->toolStripButton20->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton20->Margin = System::Windows::Forms::Padding(1);
			this->toolStripButton20->Name = L"toolStripButton20";
			this->toolStripButton20->Size = System::Drawing::Size(40, 40);
			this->toolStripButton20->Text = L"toolStripButton6";
			// 
			// toolStripButton21
			// 
			this->toolStripButton21->AutoSize = false;
			this->toolStripButton21->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton21.Image")));
			this->toolStripButton21->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton21->Name = L"toolStripButton21";
			this->toolStripButton21->Size = System::Drawing::Size(50, 50);
			this->toolStripButton21->Text = L"toolStripButton7";
			// 
			// toolStripButton22
			// 
			this->toolStripButton22->AutoSize = false;
			this->toolStripButton22->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton22.Image")));
			this->toolStripButton22->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton22->Name = L"toolStripButton22";
			this->toolStripButton22->Size = System::Drawing::Size(29, 24);
			this->toolStripButton22->Text = L"toolStripButton1";
			// 
			// toolStripButton23
			// 
			this->toolStripButton23->AutoSize = false;
			this->toolStripButton23->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton23.Image")));
			this->toolStripButton23->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton23->Name = L"toolStripButton23";
			this->toolStripButton23->Size = System::Drawing::Size(29, 24);
			this->toolStripButton23->Text = L"toolStripButton1";
			// 
			// toolStripButton24
			// 
			this->toolStripButton24->AutoSize = false;
			this->toolStripButton24->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton24.Image")));
			this->toolStripButton24->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton24->Name = L"toolStripButton24";
			this->toolStripButton24->Size = System::Drawing::Size(29, 24);
			this->toolStripButton24->Text = L"toolStripButton1";
			// 
			// toolStripButton25
			// 
			this->toolStripButton25->AutoSize = false;
			this->toolStripButton25->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton25.Image")));
			this->toolStripButton25->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton25->Name = L"toolStripButton25";
			this->toolStripButton25->Size = System::Drawing::Size(29, 24);
			this->toolStripButton25->Text = L"toolStripButton1";
			// 
			// toolStripButton26
			// 
			this->toolStripButton26->AutoSize = false;
			this->toolStripButton26->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton26.Image")));
			this->toolStripButton26->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton26->Name = L"toolStripButton26";
			this->toolStripButton26->Size = System::Drawing::Size(29, 24);
			this->toolStripButton26->Text = L"toolStripButton1";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->NotePictureBox);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox1);
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(38, 237);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1395, 480);
			this->flowLayoutPanel1->TabIndex = 10;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(3, 138);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(442, 129);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->toolStrip3);
			this->Controls->Add(this->toolStrip2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->StreamTextBox);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"EditForm";
			this->Text = L"EditForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &EditForm::EditForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &EditForm::EditForm_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NotePictureBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->toolStrip3->ResumeLayout(false);
			this->toolStrip3->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
	}
};
}
