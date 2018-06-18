#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

[STAThreadAttribute]
//function main


void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Player::MyForm form;
	Application::Run(%form);
}

void Player::MyForm::getBmpFromResource(System::Windows::Forms::PictureBox^ picBox, unsigned long resourceID)
{
	if (picBox->Image != nullptr)
		delete picBox->Image;
	Module^ mod = Assembly::GetExecutingAssembly()->GetModules()[0];
	IntPtr hInst = Marshal::GetHINSTANCE(mod);
	HANDLE hbi = LoadImage((HINSTANCE)hInst.ToPointer(), MAKEINTRESOURCE(resourceID), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
	picBox->Image = Bitmap::FromHbitmap(IntPtr(hbi));
	DeleteObject(hbi);
	delete hInst;
	delete mod;
}

std::wstring Player::MyForm::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void Player::MyForm::LoadFromFile(String ^File, ListBox^ listBox1)
{ //чтение из файла
	String ^d, ^b;
	listBox1->Items->Clear();
	try {
		b = System::IO::File::ReadAllText(File);
	}
	catch (...) {
		System::IO::File::WriteAllText("base.txt", "");
		return;
	}
	while (b->Length>0) {
		int i = b->IndexOf("\n");
		if (i<0) continue;
		d = b->Substring(0, i);
		listBox1->Items->Add(d);
		b = b->Substring(i + 1, b->Length - d->Length - 1);
	}
	this->listBox1->SelectedIndex = -1;
}

void Player::MyForm::SaveToFile(String ^File, ListBox^  listBox1)
{ //запись в файл
	String^ a;
	String^ b;
	int n = listBox1->Items->Count;
	System::IO::File::Delete(File);
	for (int i = 0; i<n; i++)
	{
		a = listBox1->Items[i]->ToString();
		b += a->Concat(a, "\n");
	}
	System::IO::File::AppendAllText(File, b);
}

/* Return TRUE if file 'fileName' exists */
bool Player::MyForm::FileExists(const TCHAR *fileName)
{
	DWORD fileAttr;

	fileAttr = GetFileAttributes(fileName);
	if (0xFFFFFFFF == fileAttr)
		return false;
	return true;
}

void Player::MyForm::updateVolume()
{
	int vol = volumeBar->Value;
	if (m_currentVolume != vol)
	{
		m_currentVolume = vol;
		vol = 7000 - (vol*7000)/50;
		vol = -vol;
		m_playerDll->SetVolume(vol);
	}
}

void Player::MyForm::updateProgressLabels()
{
	currentPositionLabel->Text = System::String::Format(L"{0}:{1,2:D2}", m_currentPosition / 60, m_currentPosition % 60);
	songDurationLabel->Text = System::String::Format(L"{0}:{1,2:D2}", m_songDuration / 60, m_songDuration % 60);
}
