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
	static void ConvertMIDI(String^ format, String^ fileName, String^ newFilePath, String^ soundFontName) {
		String^ command = "/C " + Directory::GetCurrentDirectory() + "\\TotalAudioConverter\\AudioConverter.exe ";
		command += fileName + " ";
		command += newFilePath + " ";
		command += "-sf " + soundFontName + " ";
		command += "-c " + format + " ";
		Process^ process = Process::Start("powershell.exe", command);
		process->WaitForExit();
		process->Close();
	}
};
