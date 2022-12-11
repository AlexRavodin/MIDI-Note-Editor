#pragma once

#include "EditForm.h"

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
	private: System::Windows::Forms::Button^ FileOpenBtn;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ÒÔ‡‚Í‡ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ì‡ÒÚÓÈÍËToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->FileOpenBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ì‡ÒÚÓÈÍËToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÒÔ‡‚Í‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// FileOpenBtn
			// 
			this->FileOpenBtn->AllowDrop = true;
			this->FileOpenBtn->Location = System::Drawing::Point(24, 128);
			this->FileOpenBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->FileOpenBtn->Name = L"FileOpenBtn";
			this->FileOpenBtn->Size = System::Drawing::Size(140, 67);
			this->FileOpenBtn->TabIndex = 0;
			this->FileOpenBtn->Text = L"button1";
			this->FileOpenBtn->UseVisualStyleBackColor = true;
			this->FileOpenBtn->Click += gcnew System::EventHandler(this, &StartForm::FileOpenBtn_Click);
			this->FileOpenBtn->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &StartForm::FileOpenBtn_DragDrop);
			this->FileOpenBtn->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &StartForm::FileOpenBtn_DragEnter);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 31.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(27, 39);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(688, 58);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ƒÓ·Ó ÔÓÊ‡ÎÓ‚‡Ú¸ ‚ Â‰‡ÍÚÓ ÌÓÚ.\r\n";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->Ù‡ÈÎToolStripMenuItem,
					this->Ì‡ÒÚÓÈÍËToolStripMenuItem, this->ÒÔ‡‚Í‡ToolStripMenuItem, this->Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(746, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// Ì‡ÒÚÓÈÍËToolStripMenuItem
			// 
			this->Ì‡ÒÚÓÈÍËToolStripMenuItem->Name = L"Ì‡ÒÚÓÈÍËToolStripMenuItem";
			this->Ì‡ÒÚÓÈÍËToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->Ì‡ÒÚÓÈÍËToolStripMenuItem->Text = L"Õ‡ÒÚÓÈÍË";
			// 
			// ÒÔ‡‚Í‡ToolStripMenuItem
			// 
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Name = L"ÒÔ‡‚Í‡ToolStripMenuItem";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Text = L"—Ô‡‚Í‡";
			// 
			// Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem
			// 
			this->Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem->Name = L"Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem";
			this->Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem->Size = System::Drawing::Size(107, 20);
			this->Ó–‡Á‡·ÓÚ˜ËÍÂToolStripMenuItem->Text = L"Œ ‡Á‡·ÓÚ˜ËÍÂ";
			// 
			// button1
			// 
			this->button1->AllowDrop = true;
			this->button1->Location = System::Drawing::Point(24, 199);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 67);
			this->button1->TabIndex = 3;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->AllowDrop = true;
			this->button2->Location = System::Drawing::Point(24, 270);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 67);
			this->button2->TabIndex = 4;
			this->button2->Text = L"button1";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(746, 482);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->FileOpenBtn);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Õ‡˜‡Î¸ÌÓÂ ÓÍÌÓ";
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
		MIDINoteEditor::EditForm^ editForm = gcnew MIDINoteEditor::EditForm("", this);
		this->Hide();
		editForm->Show();
	}
	private: System::Void StartForm_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ path = System::IO::Path::GetDirectoryName(Application::ExecutablePath);
		//FileOpenBtn->Image = Image::FromFile(System::IO::Path::GetDirectoryName(Application::ExecutablePath) + "\\Icons\\uploadIcon.png");
		label1->BackColor = Color::Transparent;
	}
	};

}