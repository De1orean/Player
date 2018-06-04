
#pragma once

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
		bool playCheck = false;
	
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
		}
	private: System::Windows::Forms::Panel^  leftPanel;
	protected:

	private: System::Windows::Forms::PictureBox^  panelBut;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  playBut;

	private: System::Windows::Forms::PictureBox^  nextSongBut;
	private: System::Windows::Forms::PictureBox^  pervSongBut;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panel2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->playBut = (gcnew System::Windows::Forms::PictureBox());
			this->nextSongBut = (gcnew System::Windows::Forms::PictureBox());
			this->pervSongBut = (gcnew System::Windows::Forms::PictureBox());
			this->leftPanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panelBut = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextSongBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pervSongBut))->BeginInit();
			this->leftPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelBut))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 300);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(692, 98);
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
			this->playBut->Location = System::Drawing::Point(311, 309);
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
			this->leftPanel->Controls->Add(this->pictureBox1);
			this->leftPanel->Controls->Add(this->panelBut);
			this->leftPanel->ForeColor = System::Drawing::Color::Transparent;
			this->leftPanel->Location = System::Drawing::Point(0, 0);
			this->leftPanel->Name = L"leftPanel";
			this->leftPanel->Size = System::Drawing::Size(46, 302);
			this->leftPanel->TabIndex = 11;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(44, 44);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
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
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(45, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(647, 302);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panelBut))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


//Загрузка формы
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//volumeBar->BackColor = 
}

		 //Изменение пикчербоксов при входе мыши


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
		 
//Изменение плей при нажатии

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

private: System::Void panelBut_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (leftPanel->Width != 186)
		for (int i = 46; i < 186; i++)
			leftPanel->Width += 1;
	else
		for (int i = 46; i < 186; i++)
			leftPanel -> Width -= 1;
}
};
}
