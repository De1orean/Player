
#pragma once
#include <string>
#include <list>
#include <iterator>
#include <vcclr.h>
#include <Windows.h>
#include "LibMP3DLL.h"
#include "resource.h"

//struct Name
//{
//	std::string shortName;
//	std::string path;
//};
//
//struct playList
//{
//	playList* prevSong;
//	playList* nextSong;
//	Name* songname;
//};

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  songName;
	private: System::Windows::Forms::TrackBar^  progressBar;


	private: System::Windows::Forms::TrackBar^  volumeBar;

	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Timer^  updateTimer;
	private: System::Windows::Forms::Label^  songDurationLabel;
	private: System::Windows::Forms::Label^  currentPositionLabel;




	public:
		bool playCheck = false;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			m_playerDll = new CLibMP3DLL();
			if (m_playerDll->LoadDLL(L"LibMP3DLL.dll"))
			{
				m_playerDll->SetVolume(0);
			}
			else
			{
				MessageBox::Show("LibMP3DLL.dll is not loaded!\nClosing application...", "Error");
				exit(1);
			}

			isPlaying = false;
			pause = false;
			m_songDuration = 0;

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

			if (isPlaying)
			{
				isPlaying = false;
				m_playerDll->Stop();
			}

			if (m_playerDll)
			{
				m_playerDll->Cleanup();
				m_playerDll->UnloadDLL();
				delete m_playerDll;
				m_playerDll = nullptr;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ListBox^  listBox1;

	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Panel^  leftPanel;
	private: System::Windows::Forms::Label^  SettingsLagel;
	private: System::Windows::Forms::PictureBox^  panelBut;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  playBut;

	private: System::Windows::Forms::PictureBox^  nextSongBut;
	private: System::Windows::Forms::PictureBox^  prevSongBut;

	private: System::Windows::Forms::PictureBox^  settingsBut;
	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>

		CLibMP3DLL* m_playerDll;
		bool isPlaying = false;
		bool pause;
		unsigned int m_songDuration;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->playBut = (gcnew System::Windows::Forms::PictureBox());
			this->nextSongBut = (gcnew System::Windows::Forms::PictureBox());
			this->prevSongBut = (gcnew System::Windows::Forms::PictureBox());
			this->leftPanel = (gcnew System::Windows::Forms::Panel());
			this->SettingsLagel = (gcnew System::Windows::Forms::Label());
			this->settingsBut = (gcnew System::Windows::Forms::PictureBox());
			this->panelBut = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->songName = (gcnew System::Windows::Forms::Label());
			this->progressBar = (gcnew System::Windows::Forms::TrackBar());
			this->volumeBar = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->songDurationLabel = (gcnew System::Windows::Forms::Label());
			this->currentPositionLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextSongBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prevSongBut))->BeginInit();
			this->leftPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelBut))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->progressBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
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
			this->playBut->Location = System::Drawing::Point(311, 318);
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
			this->nextSongBut->Location = System::Drawing::Point(387, 330);
			this->nextSongBut->Name = L"nextSongBut";
			this->nextSongBut->Size = System::Drawing::Size(50, 50);
			this->nextSongBut->TabIndex = 9;
			this->nextSongBut->TabStop = false;
			this->nextSongBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::nextSongBut_MouseEnter);
			this->nextSongBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::nextSongBut_MouseLeave);
			// 
			// prevSongBut
			// 
			this->prevSongBut->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->prevSongBut->BackColor = System::Drawing::Color::Transparent;
			this->prevSongBut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prevSongBut.BackgroundImage")));
			this->prevSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prevSongBut.Image")));
			this->prevSongBut->Location = System::Drawing::Point(255, 330);
			this->prevSongBut->Name = L"prevSongBut";
			this->prevSongBut->Size = System::Drawing::Size(50, 50);
			this->prevSongBut->TabIndex = 10;
			this->prevSongBut->TabStop = false;
			this->prevSongBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::pervSongBut_MouseEnter);
			this->prevSongBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::pervSongBut_MouseLeave);
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
			this->leftPanel->Size = System::Drawing::Size(44, 308);
			this->leftPanel->TabIndex = 11;
			// 
			// SettingsLagel
			// 
			this->SettingsLagel->AutoSize = true;
			this->SettingsLagel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->SettingsLagel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SettingsLagel->ForeColor = System::Drawing::SystemColors::Desktop;
			this->SettingsLagel->Location = System::Drawing::Point(46, 67);
			this->SettingsLagel->Name = L"SettingsLagel";
			this->SettingsLagel->Size = System::Drawing::Size(90, 25);
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
			this->panelBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelBut.Image")));
			this->panelBut->Location = System::Drawing::Point(0, 0);
			this->panelBut->Name = L"panelBut";
			this->panelBut->Size = System::Drawing::Size(44, 44);
			this->panelBut->TabIndex = 0;
			this->panelBut->TabStop = false;
			this->panelBut->Click += gcnew System::EventHandler(this, &MyForm::panelBut_Click);
			this->panelBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelBut_MouseEnter);
			this->panelBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelBut_MouseLeave);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->listBox1);
			this->panel1->Location = System::Drawing::Point(419, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(273, 309);
			this->panel1->TabIndex = 12;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(240, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(30, 30);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseEnter);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Playlist";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(237)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 15;
			this->listBox1->Location = System::Drawing::Point(0, 50);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(273, 255);
			this->listBox1->TabIndex = 0;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Music Files (*.mp3)|*.mp3|All files (*.*)|*.*";
			this->openFileDialog1->ValidateNames = false;
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->pictureBox3->Location = System::Drawing::Point(-1, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(693, 51);
			this->pictureBox3->TabIndex = 14;
			this->pictureBox3->TabStop = false;
			// 
			// songName
			// 
			this->songName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->songName->AutoSize = true;
			this->songName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->songName->Location = System::Drawing::Point(50, 96);
			this->songName->Name = L"songName";
			this->songName->Size = System::Drawing::Size(205, 42);
			this->songName->TabIndex = 15;
			this->songName->Text = L"SongName";
			// 
			// progressBar
			// 
			this->progressBar->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->progressBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->progressBar->Location = System::Drawing::Point(12, 330);
			this->progressBar->Maximum = 100;
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(225, 45);
			this->progressBar->TabIndex = 16;
			// 
			// volumeBar
			// 
			this->volumeBar->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->volumeBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->volumeBar->Location = System::Drawing::Point(512, 330);
			this->volumeBar->Name = L"volumeBar";
			this->volumeBar->Size = System::Drawing::Size(168, 45);
			this->volumeBar->TabIndex = 17;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(483, 330);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(30, 30);
			this->pictureBox4->TabIndex = 18;
			this->pictureBox4->TabStop = false;
			// 
			// updateTimer
			// 
			this->updateTimer->Enabled = true;
			this->updateTimer->Interval = 1000;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MyForm::updateTimer_Timeout);
			// 
			// songDurationLabel
			// 
			this->songDurationLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->songDurationLabel->AutoSize = true;
			this->songDurationLabel->BackColor = System::Drawing::SystemColors::GrayText;
			this->songDurationLabel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->songDurationLabel->Location = System::Drawing::Point(200, 362);
			this->songDurationLabel->Name = L"songDurationLabel";
			this->songDurationLabel->Size = System::Drawing::Size(28, 13);
			this->songDurationLabel->TabIndex = 19;
			this->songDurationLabel->Text = L"0:00";
			// 
			// currentPositionLabel
			// 
			this->currentPositionLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->currentPositionLabel->AutoSize = true;
			this->currentPositionLabel->BackColor = System::Drawing::SystemColors::GrayText;
			this->currentPositionLabel->Location = System::Drawing::Point(25, 362);
			this->currentPositionLabel->Name = L"currentPositionLabel";
			this->currentPositionLabel->Size = System::Drawing::Size(28, 13);
			this->currentPositionLabel->TabIndex = 20;
			this->currentPositionLabel->Text = L"0:00";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(692, 398);
			this->Controls->Add(this->currentPositionLabel);
			this->Controls->Add(this->songDurationLabel);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->volumeBar);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->leftPanel);
			this->Controls->Add(this->prevSongBut);
			this->Controls->Add(this->nextSongBut);
			this->Controls->Add(this->playBut);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->songName);
			this->Controls->Add(this->pictureBox3);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Blueberry";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextSongBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prevSongBut))->EndInit();
			this->leftPanel->ResumeLayout(false);
			this->leftPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelBut))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->progressBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/**********************************************************************************************/

		//�������� �����

		/**********************************************************************************************/
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
	LoadFromFile("base.txt", this->listBox1);
	}
			 /**********************************************************************************************/

			 //��������� ������������ ��� ����� ����

			 /**********************************************************************************************/
	private: System::Void pervSongBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(prevSongBut, IDB_BTN_PREV_SONG_ENTER);
	}

	private: System::Void pervSongBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(prevSongBut, IDB_BTN_PREV_SONG);
	}
	private: System::Void nextSongBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(nextSongBut, IDB_BTN_NEXT_SONG_ENTER);
	}

	private: System::Void nextSongBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(nextSongBut, IDB_BTN_NEXT_SONG);
	}

	private: System::Void panelBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(panelBut, IDB_BTN_PANEL_ENTER);
	}
	private: System::Void panelBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(panelBut, IDB_BTN_PANEL);
	}

	private: System::Void settingsBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		if (settingsBut->Width < 150)
		{
			getBmpFromResource(settingsBut, IDB_BTN_SETTINGS_ENTER_BIG);

		}
		else
		{
			getBmpFromResource(settingsBut, IDB_BTN_SETTINGS_ENTER_BIG);
			SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 206, 206, 206);
		}
	}
	private: System::Void settingsBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(settingsBut, IDB_BTN_SETTINGS);
		SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 225, 226, 225);
	}
	private: System::Void pictureBox1_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(pictureBox1, IDB_BTN_OPEN_FILE);
	}
	private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(pictureBox1, IDB_BTN_OPEN_FILE);
	}
	private: System::Void SettingsLagel_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(settingsBut, IDB_BTN_SETTINGS_ENTER);
		SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 206, 206, 206);
	}
	private: System::Void SettingsLagel_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(settingsBut, IDB_BTN_SETTINGS);
		SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 225, 226, 225);
	}

			 /**********************************************************************************************/

			 //��������� ���� ��� �������

			 /**********************************************************************************************/
	private: System::Void playBut_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (isPlaying)
		{
			isPlaying = false;
			getBmpFromResource(playBut, IDB_BTN_PLAY_ENTER);
			m_playerDll->Pause();
		}
		else
		{
			if (m_playerDll->Load(L"../song_to_play.mp3") && m_playerDll->Play())
			{
				isPlaying = true;
				getBmpFromResource(playBut, IDB_BTN_PAUSE_ENTER);
			}
			//Mp3Player->Load(StringtoLPCWSTR(listBox1->Items[0]->ToString()));
			//Mp3Player->Play();
			//Mp3Player->
		}
	}
			 /**********************************************************************************************/

			 //��������� ���� ��� ���������

			 /**********************************************************************************************/
	private: System::Void playBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		if (isPlaying)
		{
			getBmpFromResource(playBut, IDB_BTN_PAUSE_ENTER);
		}
		else
		{
			getBmpFromResource(playBut, IDB_BTN_PLAY_ENTER);
		}
	}
	private: System::Void playBut_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		if (isPlaying)
		{
			getBmpFromResource(playBut, IDB_BTN_PAUSE);
		}
		else
		{
			getBmpFromResource(playBut, IDB_BTN_PLAY);
		}
	}
			 /**********************************************************************************************/

			 //��������� ������

			 /**********************************************************************************************/
	private: System::Void panelBut_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (leftPanel->Width != 184)
		{
			for (int i = 44; i < 184; i++)
			{
				leftPanel->Width += 1;
				settingsBut->Width += 1;
			}

		}
		else
		{
			for (int i = 44; i < 184; i++)
			{
				leftPanel->Width -= 1;
				settingsBut->Width -= 1;
			}
		}
	}

	private: System::Void settingsBut_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			
		}
	}

	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		listBox1->Items->Add(openFileDialog1->FileName);
		songName->Text = openFileDialog1->FileName;
	}

	private: void getBmpFromResource(System::Windows::Forms::PictureBox^ picBox, unsigned long resourceID);

	private: std::wstring s2ws(const std::string& s);
	
	private: LPCWSTR StringtoLPCWSTR(String^ s)
	{
		pin_ptr<const wchar_t> wname = PtrToStringChars(s);
		return wname;
	};
	private: void LoadFromFile(String^ File, ListBox^ listBox1);

	private: void SaveToFile(String ^File, ListBox^  listBox1);
	
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		SaveToFile("base.txt", this->listBox1);
	}

	private: System::Void updateTimer_Timeout(System::Object^  sender, System::EventArgs^  e)
	{
		if(isPlaying)
			//TODO: getCurrentPosition dll method should be invoked here
			// this value should be assigned to progressBar->Value
			// currentPositionLabel and songDurationLabel must be updated
			// private field m_songDuration stores duration of currently playing song

			if (progressBar->Value < progressBar->Maximum - 1)
			{
				progressBar->Value++;
				unsigned short current_sec = progressBar->Value % 60;

				currentPositionLabel->Text = System::Convert::ToString(progressBar->Value / 60) + ":" + ((current_sec < 10)? "0"+System::Convert::ToString(current_sec):System::Convert::ToString(current_sec));
				songDurationLabel->Text =  System::Convert::ToString(progressBar->Maximum / 60) + ":" + System::Convert::ToString(progressBar->Maximum % 60);
			}
			else
				progressBar->Value = 0;
	}
	private:
		static bool FileExists(const TCHAR *fileName);
		int GetVolume();
};

}