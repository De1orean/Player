
#pragma once
#include <string>
#include <list>
#include <iterator>
#include <vcclr.h>
#include <Windows.h>
#include "LibMP3DLL.h"
#include "resource.h"

#define not !
#define and &&
#define or ||

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
	/// Сводка для MyForm
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
	private: System::Windows::Forms::PictureBox^  btnVolume;



	private: System::Windows::Forms::Timer^  updateTimer;
	private: System::Windows::Forms::Label^  songDurationLabel;
	private: System::Windows::Forms::Label^  currentPositionLabel;
	private: System::Windows::Forms::PictureBox^  deleteItem;






	public:
		bool playCheck = false;
	public:
		MyForm(void) :
			isPlaying(false),
			pause(false),
			m_songDuration(0),
			m_currentVolume(0),
			m_currentPosition(0),
			m_step(0)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			m_playerDll = new CLibMP3DLL();
			if (not m_playerDll->LoadDLL(L"LibMP3DLL.dll"))
			{
				MessageBox::Show("LibMP3DLL.dll is not loaded!\nClosing application...", "Error");
				exit(1);
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		/// Обязательная переменная конструктора.
		/// </summary>

		CLibMP3DLL* m_playerDll;
		bool isPlaying = false;
		bool isVolumeOn = true;
		bool pause;
		unsigned int m_songDuration;
		int m_currentVolume;
		unsigned int m_currentPosition;
		unsigned int m_step;

	private:
		static bool FileExists(const TCHAR *fileName);
		void updateVolume();
		void updateProgressLabels();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->songName = (gcnew System::Windows::Forms::Label());
			this->progressBar = (gcnew System::Windows::Forms::TrackBar());
			this->volumeBar = (gcnew System::Windows::Forms::TrackBar());
			this->btnVolume = (gcnew System::Windows::Forms::PictureBox());
			this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->songDurationLabel = (gcnew System::Windows::Forms::Label());
			this->currentPositionLabel = (gcnew System::Windows::Forms::Label());
			this->deleteItem = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextSongBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prevSongBut))->BeginInit();
			this->leftPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->progressBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolume))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deleteItem))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 288);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(692, 110);
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
			this->playBut->Location = System::Drawing::Point(311, 323);
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
			this->nextSongBut->Location = System::Drawing::Point(387, 334);
			this->nextSongBut->Name = L"nextSongBut";
			this->nextSongBut->Size = System::Drawing::Size(50, 50);
			this->nextSongBut->TabIndex = 9;
			this->nextSongBut->TabStop = false;
			this->nextSongBut->Click += gcnew System::EventHandler(this, &MyForm::nextSongBut_Click);
			this->nextSongBut->MouseEnter += gcnew System::EventHandler(this, &MyForm::nextSongBut_MouseEnter);
			this->nextSongBut->MouseLeave += gcnew System::EventHandler(this, &MyForm::nextSongBut_MouseLeave);
			// 
			// prevSongBut
			// 
			this->prevSongBut->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->prevSongBut->BackColor = System::Drawing::Color::Transparent;
			this->prevSongBut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prevSongBut.BackgroundImage")));
			this->prevSongBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prevSongBut.Image")));
			this->prevSongBut->Location = System::Drawing::Point(255, 334);
			this->prevSongBut->Name = L"prevSongBut";
			this->prevSongBut->Size = System::Drawing::Size(50, 50);
			this->prevSongBut->TabIndex = 10;
			this->prevSongBut->TabStop = false;
			this->prevSongBut->Click += gcnew System::EventHandler(this, &MyForm::prevSongBut_Click);
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
			this->leftPanel->Size = System::Drawing::Size(44, 288);
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
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(650, 12);
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
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(159)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(464, 13);
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
			this->listBox1->Location = System::Drawing::Point(469, 51);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(223, 240);
			this->listBox1->TabIndex = 0;
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::listBox1_DoubleClick);
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
			this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(159)));
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
			this->progressBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->progressBar->LargeChange = 0;
			this->progressBar->Location = System::Drawing::Point(12, 294);
			this->progressBar->Maximum = 1000;
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(668, 45);
			this->progressBar->TabIndex = 16;
			this->progressBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->progressBar->Scroll += gcnew System::EventHandler(this, &MyForm::progressBar_Scroll);
			// 
			// volumeBar
			// 
			this->volumeBar->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->volumeBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->volumeBar->Location = System::Drawing::Point(512, 342);
			this->volumeBar->Maximum = 50;
			this->volumeBar->Name = L"volumeBar";
			this->volumeBar->Size = System::Drawing::Size(168, 45);
			this->volumeBar->TabIndex = 17;
			this->volumeBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->volumeBar->Value = 35;
			this->volumeBar->Scroll += gcnew System::EventHandler(this, &MyForm::volumeBar_Scroll);
			this->volumeBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::volumeBar_ValueChanged);
			// 
			// btnVolume
			// 
			this->btnVolume->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->btnVolume->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->btnVolume->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolume.Image")));
			this->btnVolume->Location = System::Drawing::Point(483, 342);
			this->btnVolume->Name = L"btnVolume";
			this->btnVolume->Size = System::Drawing::Size(30, 30);
			this->btnVolume->TabIndex = 18;
			this->btnVolume->TabStop = false;
			this->btnVolume->Click += gcnew System::EventHandler(this, &MyForm::btnVolume_Click);
			this->btnVolume->MouseEnter += gcnew System::EventHandler(this, &MyForm::btnVolume_MouseEnter);
			this->btnVolume->MouseLeave += gcnew System::EventHandler(this, &MyForm::btnVolume_MouseLeave);
			// 
			// updateTimer
			// 
			this->updateTimer->Enabled = true;
			this->updateTimer->Interval = 500;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MyForm::updateTimer_Timeout);
			// 
			// songDurationLabel
			// 
			this->songDurationLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->songDurationLabel->AutoSize = true;
			this->songDurationLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)), static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->songDurationLabel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->songDurationLabel->ForeColor = System::Drawing::Color::White;
			this->songDurationLabel->Location = System::Drawing::Point(652, 321);
			this->songDurationLabel->Name = L"songDurationLabel";
			this->songDurationLabel->Size = System::Drawing::Size(28, 13);
			this->songDurationLabel->TabIndex = 19;
			this->songDurationLabel->Text = L"0:00";
			// 
			// currentPositionLabel
			// 
			this->currentPositionLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->currentPositionLabel->AutoSize = true;
			this->currentPositionLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)), static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->currentPositionLabel->ForeColor = System::Drawing::Color::White;
			this->currentPositionLabel->Location = System::Drawing::Point(16, 321);
			this->currentPositionLabel->Name = L"currentPositionLabel";
			this->currentPositionLabel->Size = System::Drawing::Size(28, 13);
			this->currentPositionLabel->TabIndex = 20;
			this->currentPositionLabel->Text = L"0:00";
			// 
			// deleteItem
			// 
			this->deleteItem->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->deleteItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deleteItem.Image")));
			this->deleteItem->Location = System::Drawing::Point(614, 12);
			this->deleteItem->Name = L"deleteItem";
			this->deleteItem->Size = System::Drawing::Size(30, 30);
			this->deleteItem->TabIndex = 21;
			this->deleteItem->TabStop = false;
			this->deleteItem->Click += gcnew System::EventHandler(this, &MyForm::deleteItem_Click);
			this->deleteItem->MouseEnter += gcnew System::EventHandler(this, &MyForm::deleteItem_MouseEnter);
			this->deleteItem->MouseLeave += gcnew System::EventHandler(this, &MyForm::deleteItem_MouseLeave);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(692, 398);
			this->Controls->Add(this->deleteItem);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->currentPositionLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->songDurationLabel);
			this->Controls->Add(this->btnVolume);
			this->Controls->Add(this->volumeBar);
			this->Controls->Add(this->leftPanel);
			this->Controls->Add(this->prevSongBut);
			this->Controls->Add(this->nextSongBut);
			this->Controls->Add(this->playBut);
			this->Controls->Add(this->songName);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->listBox1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->progressBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolume))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deleteItem))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/**********************************************************************************************/

		//Загрузка формы

		/**********************************************************************************************/
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		LoadFromFile("base.txt", this->listBox1);
	}
			 /**********************************************************************************************/

			 //Изменение пикчербоксов при входе мыши

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
		getBmpFromResource(pictureBox1, IDB_ADD_ITEM_ENTER);
	}
	private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(pictureBox1, IDB_ADD_ITEM);
	}
	private: System::Void SettingsLagel_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(settingsBut, IDB_BTN_SETTINGS_ENTER_BIG);
		SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 206, 206, 206);
	}
	private: System::Void SettingsLagel_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		getBmpFromResource(settingsBut, IDB_BTN_SETTINGS);
		SettingsLagel->BackColor = System::Drawing::Color::FromArgb(255, 225, 226, 225);
	}

			 /**********************************************************************************************/

			 //Изменение плей при нажатии

			 /**********************************************************************************************/
	private: System::Void playBut_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (isPlaying)
		{
			if (not pause)
			{
				pause = true;
				getBmpFromResource(playBut, IDB_BTN_PLAY_ENTER);
				m_playerDll->Pause();
			}
			else
			{
				pause = false;
				m_playerDll->Play();
				getBmpFromResource(playBut, IDB_BTN_PAUSE_ENTER);
			}
		}
		else
		{
			if (m_playerDll->Load(StringtoLPCWSTR(listBox1->Items[listBox1->SelectedIndex]->ToString())) && m_playerDll->Play())
			{
				updateVolume();
				isPlaying = true;
				getBmpFromResource(playBut, IDB_BTN_PAUSE_ENTER);
				m_songDuration = m_playerDll->GetDuration() / 10000000;
				updateProgressLabels();
			}
		}
	}
			 /**********************************************************************************************/

			 //изменение плей при наведении

			 /**********************************************************************************************/
	private: System::Void playBut_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		if (isPlaying and not pause)
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
		if (isPlaying and not pause)
		{
			getBmpFromResource(playBut, IDB_BTN_PAUSE);
		}
		else
		{
			getBmpFromResource(playBut, IDB_BTN_PLAY);
		}
	}
			 /**********************************************************************************************/

			 //выезжание панели

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
		if (isPlaying and not pause)
		{
			m_currentPosition = m_playerDll->GetCurrentPosition() / 10000000;
			int position = m_currentPosition * 1000 / m_songDuration;
			updateProgressLabels();
			if (position <= progressBar->Maximum)
			{
				progressBar->Value = position;
			}
		}
	}
	private: System::Void volumeBar_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		updateVolume();
	}
	private: System::Void progressBar_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		if (isPlaying and pause == false)
		{
			__int64 duration = m_playerDll->GetDuration();
			__int64 pos = progressBar->Value * duration / progressBar->Maximum;
			m_playerDll->SetPositions(&pos, &duration, true);
		}
		else
		{
			__int64 duration = m_playerDll->GetDuration();
			__int64 pos = progressBar->Value * duration / progressBar->Maximum;
			__int64 posStop = pos;

			if (pause == true)
			{
				m_playerDll->SetPositions(&pos, &duration, true);
				m_playerDll->Pause();
			}
			else
			{
				m_playerDll->SetPositions(&pos, &posStop, true);
			}
		}

		__int64 durationTemp = m_playerDll->GetDuration() / 10000000;
		__int64 curPos = m_playerDll->GetCurrentPosition();

		__int64 timeElapsedSec = curPos / 10000000;
	}

	private: System::Void btnVolume_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (isVolumeOn)
		{
			getBmpFromResource(btnVolume, IDB_VOLUME_OFF_ENTER);
			volumeBar->Value = volumeBar->Minimum;
			isVolumeOn = false;
		}
		else
		{
			getBmpFromResource(btnVolume, IDB_VOLUME_ENTER);
			volumeBar->Value = volumeBar->Maximum;
			isVolumeOn = true;
		}
	}
	private: System::Void volumeBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		updateVolume();
	}
private: System::Void btnVolume_MouseEnter(System::Object^  sender, System::EventArgs^  e) 
{
	if (isVolumeOn)
	{
		if (volumeBar->Value == volumeBar->Minimum)
			getBmpFromResource(btnVolume, IDB_VOLUME_OFF_ENTER);
		else
			getBmpFromResource(btnVolume, IDB_VOLUME_ENTER);
	}
	else
	{
		getBmpFromResource(btnVolume, IDB_VOLUME_OFF_ENTER);
	}
}
private: System::Void btnVolume_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
{
	if (isVolumeOn)
	{
		if (volumeBar->Value == volumeBar->Minimum)
			getBmpFromResource(btnVolume, IDB_VOLUME_OFF);
		else
			getBmpFromResource(btnVolume, IDB_VOLUME);
	}
	else
	{
		getBmpFromResource(btnVolume, IDB_VOLUME_OFF);
	}
}

private: System::Void deleteItem_MouseEnter(System::Object^  sender, System::EventArgs^  e) 
{
	getBmpFromResource(deleteItem, IDB_DELETE_ITEM_ENTER);
}
	
private: System::Void deleteItem_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
}
		// getBmpFromResource(deleteItem, IDB_VOLUME_OFF);
		 
private: System::Void deleteItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	listBox1->Items->RemoveAt(listBox1->SelectedIndex);
}
private: System::Void deleteItem_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
{
	getBmpFromResource(deleteItem, IDB_DELETE_ITEM);
}
private: System::Void listBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
{
	m_playerDll->Load(StringtoLPCWSTR(listBox1->Items[listBox1->SelectedIndex]->ToString()));
	m_playerDll->Play();
}
private: System::Void nextSongBut_Click(System::Object^  sender, System::EventArgs^  e) 
{
	listBox1->SetSelected(((listBox1->SelectedIndex) + 1),true);
	m_playerDll->Load(StringtoLPCWSTR(listBox1->Items[listBox1->SelectedIndex]->ToString()));
	updateVolume();
	m_songDuration = m_playerDll->GetDuration() / 10000000;
	updateProgressLabels();
	if (isPlaying)
		m_playerDll->Play();
}
private: System::Void prevSongBut_Click(System::Object^  sender, System::EventArgs^  e) 
{
	listBox1->SetSelected(((listBox1->SelectedIndex) - 1), true);
	m_playerDll->Load(StringtoLPCWSTR(listBox1->Items[listBox1->SelectedIndex]->ToString()));
	updateVolume();
	m_songDuration = m_playerDll->GetDuration() / 10000000;
	updateProgressLabels();
	if (isPlaying)
		m_playerDll->Play();
}
};

}