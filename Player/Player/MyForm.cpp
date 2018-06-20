#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

[STAThreadAttribute]
//function main


Void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Player::MyForm form;
	Application::Run(%form);
}

Void Player::MyForm::setBmpFromResource(System::Windows::Forms::PictureBox^ picBox, unsigned long resourceID)
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

Void Player::MyForm::LoadPlayList(String ^File)
{ //чтение из файла
	String ^path, ^buffer;
	listBox1->Items->Clear();
	try {
		buffer = System::IO::File::ReadAllText(File);
	}
	catch (...) {
		System::IO::File::WriteAllText("base.txt", "");
		return;
	}
	while (buffer->Length>0) {
		int i = buffer->IndexOf("\n");
		if (i<0) continue;
		path = buffer->Substring(0, i);
		addSong(path);
		buffer = buffer->Substring(i + 1, buffer->Length - path->Length - 1);
	}
	this->listBox1->SelectedIndex = -1;
}

Void Player::MyForm::SavePlayList(String ^File)
{ //запись в файл
	String^ a;
	String^ b;
	int n = m_songs->Count;
	System::IO::File::Delete(File);
	for (int i = 0; i<n; i++)
	{
		a = m_songs[i]->ToString();
		b += a->Concat(a, "\n");
	}
	System::IO::File::AppendAllText(File, b);
}

Void Player::MyForm::addSong(String ^path)
{
	array<System::String^>^ splited = path->Split('\\');
	System::String^ name = splited[splited->Length - 1];
	m_songs->Add(path);
	name = name->Substring(0,name->Length-4);
	if (name->Length > 24)
	{
		name = name->Substring(0, 20) + "...";
	}
	listBox1->Items->Add(name);
}

bool Player::MyForm::playSong(Void)
{
	if (m_playingSongIndex != -1)
	{
		listBox1->SetSelected(m_playingSongIndex, true);

		if (m_isPlaying)
		{
			if (m_playerDll->Load(StringtoLPCWSTR(m_songs[m_playingSongIndex]->ToString())) && m_playerDll->Play())
			{
				m_songDuration = m_playerDll->GetDuration() / 10000000;
				updateVolume();
				updateProgressLabels();
				setBmpFromResource(playBut, IDB_BTN_PAUSE);
				songName->Text = listBox1->Items[m_playingSongIndex]->ToString();
				return true;
			}
			else
			{
				//some error occured duting load or playing songng cannot be played
				if (listBox1->Items[m_playingSongIndex]->ToString()->IndexOf(L"Error - ") == -1)
					listBox1->Items[m_playingSongIndex] = "Error - " + listBox1->Items[m_playingSongIndex];
				m_isPlaying = false;
			}
		}
	}
	return false;
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
	vol = 7000 - (vol*7000)/50;
	vol = -vol;
	m_playerDll->SetVolume(vol);
}

void Player::MyForm::updateProgressLabels()
{
	currentPositionLabel->Text = System::String::Format(L"{0}:{1,2:D2}", m_currentPosition / 60, m_currentPosition % 60);
	songDurationLabel->Text = System::String::Format(L"{0}:{1,2:D2}", m_songDuration / 60, m_songDuration % 60);
}
