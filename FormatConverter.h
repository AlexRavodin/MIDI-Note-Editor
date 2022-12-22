#pragma once

using namespace System::Collections::Generic;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::IO;
using namespace System::Diagnostics;

ref class FormatConverter{
public:
	static void ConvertMIDI(String^ format, String^ fileName, String^ newFilePath, String^ soundFontName, int volume) {
		String^ command = "/C " + Directory::GetCurrentDirectory() + "\\TotalAudioConverter\\AudioConverter.exe ";
		//String^ command = Directory::GetCurrentDirectory() + "\\TotalAudioConverter\\AudioConverter.exe ";
		command += fileName + " ";
		command += newFilePath + " ";
		//command += "-sf " + soundFontName + " ";
		command += "-c " + format + " ";
		//command += "-rename";
		Process^ process = Process::Start("powershell.exe", command);
		process->WaitForExit();
		//while (process->HasExited && process->Responding) {}
		process->Close();
		//System::Diagnostics::Process^ playing = gcnew System::Diagnostics::Process();
		//playing->Start("CMD.exe", command);
		//playing->WaitForExit();
		//playing->Close();
	}
};
