
#pragma once

namespace Player {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		bool check = true;
		bool playCheck = false;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:
	private: System::Windows::Forms::Panel^  leftPanel;
	private: System::Windows::Forms::Label^  SettingsLagel;
	private: System::Windows::Forms::PictureBox^  panelBut;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  playBut;

	private: System::Windows::Forms::PictureBox^  nextSongBut;
	private: System::Windows::Forms::PictureBox^  pervSongBut;
	private: System::Windows::Forms::PictureBox^  settingsBut;

	private: System::Windows::Forms::Panel^  panel2;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->playBut = (gcnew System::Windows::Forms::PictureBox());
			this->nextSongBut = (gcnew System::Windows::Forms::PictureBox());
			this->pervSongBut = (gcnew System::Windows::Forms::PictureBox());
			this->leftPanel = (gcnew System::Windows::Forms::Panel());
			this->SettingsLagel = (gcnew System::Windows::Forms::Label());
			this->settingsBut = (gcnew System::Windows::Forms::PictureBox());
			this->panelBut = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextSongBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pervSongBut))->BeginInit();
			this->leftPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelBut))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 308);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(692, 90);
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// playBut
			// 
			this->playBut->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->playBut->BackColor = System::Drawing::Color::Transparent;
			this->playBut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playBut.BackgroundImage")));
			this->playBut->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playBut.Image")));
			this->playBut->Location = System::Drawing::Point(311, 308);
			this->playBut->Name = L"playBut";
			this->playBut->Size = System::Drawing::Size(70, 70);
			this->playBut->TabIndex = 8;
			this->playBut->TabStop = false;
			this->playBut->Click += gcnew System::EventHandler(this, &MyForm::playBut_Click);
			this->playBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::playBut_MouseEnter);
			this->playBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::playBut_MouseLeave);
			// 
			// nextSongBut
			// 
			this->nextSongBut->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->nextSongBut->BackColor = System::Drawing::Color::Transparent;
			this->nextSongBut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nextSongBut.BackgroundImage")));
			this->nextSongBut->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->nextSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nextSongBut.Image")));
			this->nextSongBut->Location = System::Drawing::Point(387, 320);
			this->nextSongBut->Name = L"nextSongBut";
			this->nextSongBut->Size = System::Drawing::Size(50, 50);
			this->nextSongBut->TabIndex = 9;
			this->nextSongBut->TabStop = false;
			this->nextSongBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::nextSongBut_MouseEnter);
			this->nextSongBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::nextSongBut_MouseLeave);
			// 
			// pervSongBut
			// 
			this->pervSongBut->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->pervSongBut->BackColor = System::Drawing::Color::Transparent;
			this->pervSongBut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pervSongBut.BackgroundImage")));
			this->pervSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pervSongBut.Image")));
			this->pervSongBut->Location = System::Drawing::Point(255, 320);
			this->pervSongBut->Name = L"pervSongBut";
			this->pervSongBut->Size = System::Drawing::Size(50, 50);
			this->pervSongBut->TabIndex = 10;
			this->pervSongBut->TabStop = false;
			this->pervSongBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::pervSongBut_MouseEnter_1);
			this->pervSongBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::pervSongBut_MouseLeave);
			// 
			// leftPanel
			// 
			this->leftPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->leftPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->leftPanel->Controls->Add(this->SettingsLagel);
			this->leftPanel->Controls->Add(this->settingsBut);
			this->leftPanel->Controls->Add(this->panelBut);
			this->leftPanel->ForeColor = System::Drawing::Color::Transparent;
			this->leftPanel->Location = System::Drawing::Point(0, 0);
			this->leftPanel->Name = L"leftPanel";
			this->leftPanel->Size = System::Drawing::Size(46, 302);
			this->leftPanel->TabIndex = 11;
			// 
			// SettingsLagel
			// 
			this->SettingsLagel->AutoSize = true;
			this->SettingsLagel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->SettingsLagel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SettingsLagel->ForeColor = System::Drawing::SystemColors::Desktop;
			this->SettingsLagel->Location = System::Drawing::Point(50, 65);
			this->SettingsLagel->Name = L"SettingsLagel";
			this->SettingsLagel->Size = System::Drawing::Size(100, 29);
			this->SettingsLagel->TabIndex = 13;
			this->SettingsLagel->Text = L"Settings";
			this->SettingsLagel->MouseEnter += gcnew System::EventHandler(this, &MyForm::SettingsLagel_MouseEnter);
			this->SettingsLagel->MouseLeave += gcnew System::EventHandler(this, &MyForm::SettingsLagel_MouseLeave);
			// 
			// settingsBut
			// 
			this->settingsBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsBut.Image")));
			this->settingsBut->Location = System::Drawing::Point(0, 50);
			this->settingsBut->Name = L"settingsBut";
			this->settingsBut->Size = System::Drawing::Size(44, 44);
			this->settingsBut->TabIndex = 12;
			this->settingsBut->TabStop = false;
			this->settingsBut->Click += gcnew System::EventHandler(this, &MyForm::settingsBut_Click);
			this->settingsBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::settingsBut_MouseEnter);
			this->settingsBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::settingsBut_MouseLeave);
			// 
			// panelBut
			// 
			this->panelBut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelBut.BackgroundImage")));
			this->panelBut->Location = System::Drawing::Point(0, 0);
			this->panelBut->Name = L"panelBut";
			this->panelBut->Size = System::Drawing::Size(44, 44);
			this->panelBut->TabIndex = 0;
			this->panelBut->TabStop = false;
			this->panelBut->Click += gcnew System::EventHandler(this, &MyForm::panelBut_Click);
			this->panelBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelBut_MouseEnter);
			this->panelBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelBut_MouseLeave);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(44, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(648, 302);
			this->panel2->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(692, 398);
			this->Controls->Add(this->leftPanel);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pervSongBut);
			this->Controls->Add(this->nextSongBut);
			this->Controls->Add(this->playBut);
			this->Controls->Add(this->pictureBox2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Blueberry";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextSongBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pervSongBut))->EndInit();
			this->leftPanel->ResumeLayout(false);
			this->leftPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelBut))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


//�������� �����
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//volumeBar->BackColor = 
}

		 //��������� ������������ ��� ����� ����


private: System::Void pervSongBut_MouseEnter_1(System::Object^  sender, System::EventArgs^  e)
{

	pervSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prevsongenter")));
}
private: System::Void pervSongBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	pervSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prevsong")));
}
private: System::Void nextSongBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
{
	nextSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nextsongenter")));
}

private: System::Void nextSongBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	nextSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nextsong")));

}
private: System::Void panelBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
{
		panelBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelButenter")));
}
private: System::Void panelBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	panelBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelBut")));
}

private: System::Void settingsBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
{
	if (settingsBut->Width < 150)
	{
		settingsBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsenter")));

	}
	else
	{
		settingsBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsenterbig")));
		SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 206, 206, 206);
	}
}
private: System::Void settingsBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	settingsBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settings")));
	SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 225, 226, 225);
}

		 
//��������� ���� ��� �������

private: System::Void playBut_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (check == true)
	{
		if (playCheck == true)
			playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pauseenter")));
		else
			playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pause")));
		check = false;
	}
	else
	{
		if(playCheck==true)
			playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playenter")));
		else
			playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"play")));
		check = true;
	}
}
		 //��������� ���� ��� ���������
private: System::Void playBut_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	playCheck = true;
	if (check == true)
	{
		playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playenter")));
	}
	else
		playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pauseenter")));
}
private: System::Void playBut_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	playCheck = false;
	if (check == true)
	{
		playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"play")));
	}
	else
		playBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pause")));
}

		 //��������� ������

private: System::Void panelBut_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (leftPanel->Width != 186)
	{
		for (int i = 46; i < 186; i++)
		{
			leftPanel->Width += 1;
			settingsBut->Width += 1;
		}
		
	}
	else
	{
		for (int i = 46; i < 186; i++)
		{
			leftPanel->Width -= 1;
			settingsBut->Width -= 1;
		}
	}
}



private: System::Void SettingsLagel_MouseEnter(System::Object^  sender, System::EventArgs^  e)
{
	settingsBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsenterbig")));
	SettingsLagel->BackColor = System::Drawing::Color::FromArgb( 255, 206, 206, 206);
}
private: System::Void SettingsLagel_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	settingsBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settings")));
	SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 225, 226, 225);
}
private: System::Void settingsBut_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
