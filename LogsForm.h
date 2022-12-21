#pragma once

namespace MIDINoteEditor {

	using namespace System;
	using namespace System::Text;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogsForm
	/// </summary>
	public ref class LogsForm : public System::Windows::Forms::Form
	{
	public:
		LogsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		LogsForm(StringBuilder^ logs, Form^ previousForm)
		{
			InitializeComponent();
			this->Logs = logs;
			this->PreviousForm = previousForm;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÒÔ‡‚Í‡ToolStripMenuItem;
	private: StringBuilder^ Logs;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ÒÔ‡‚Í‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(8, 32);
			this->textBox1->MaxLength = 10000000;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(400, 568);
			this->textBox1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ÒÔ‡‚Í‡ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(417, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ÒÔ‡‚Í‡ToolStripMenuItem
			// 
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Name = L"ÒÔ‡‚Í‡ToolStripMenuItem";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Text = L"—Ô‡‚Í‡";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LogsForm::ÒÔ‡‚Í‡ToolStripMenuItem_Click);
			// 
			// LogsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(417, 604);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"LogsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ÀÓ„Ë";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LogsForm::LogsForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &LogsForm::LogsForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LogsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = Logs->ToString();
	}
	private: System::Void LogsForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		PreviousForm->Enabled = true;
	}
private: System::Void ÒÔ‡‚Í‡ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//MessageBox();
}
};
}
