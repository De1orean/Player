#include "MyForm.h"
#include <Windows.h>

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

