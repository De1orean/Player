#pragma once

namespace Player {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  songName;
	protected:
	private: System::Windows::Forms::TrackBar^  volumeBar;
	private: System::Windows::Forms::TrackBar^  trackBar;
	private: System::Windows::Forms::Button^  pausePlay;
	private: System::Windows::Forms::Button^  prevSong;
	private: System::Windows::Forms::Button^  nextSong;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->songName = (gcnew System::Windows::Forms::Label());
			this->volumeBar = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar = (gcnew System::Windows::Forms::TrackBar());
			this->pausePlay = (gcnew System::Windows::Forms::Button());
			this->prevSong = (gcnew System::Windows::Forms::Button());
			this->nextSong = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// songName
			// 
			this->songName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->songName->Location = System::Drawing::Point(12, 85);
			this->songName->Name = L"songName";
			this->songName->Size = System::Drawing::Size(359, 77);
			this->songName->TabIndex = 0;
			this->songName->Text = L"Song name";
			// 
			// volumeBar
			// 
			this->volumeBar->Location = System::Drawing::Point(12, 239);
			this->volumeBar->Name = L"volumeBar";
			this->volumeBar->Size = System::Drawing::Size(104, 45);
			this->volumeBar->TabIndex = 1;
			// 
			// trackBar
			// 
			this->trackBar->Location = System::Drawing::Point(12, 170);
			this->trackBar->Name = L"trackBar";
			this->trackBar->Size = System::Drawing::Size(359, 45);
			this->trackBar->TabIndex = 2;
			// 
			// pausePlay
			// 
			this->pausePlay->Location = System::Drawing::Point(301, 214);
			this->pausePlay->Name = L"pausePlay";
			this->pausePlay->Size = System::Drawing::Size(70, 70);
			this->pausePlay->TabIndex = 3;
			this->pausePlay->Text = L"Play\r\npause\r\n";
			this->pausePlay->UseVisualStyleBackColor = true;
			this->pausePlay->Click += gcnew System::EventHandler(this, &MyForm::pausePlay_Click);
			// 
			// prevSong
			// 
			this->prevSong->Location = System::Drawing::Point(245, 224);
			this->prevSong->Name = L"prevSong";
			this->prevSong->Size = System::Drawing::Size(50, 50);
			this->prevSong->TabIndex = 4;
			this->prevSong->Text = L"prev";
			this->prevSong->UseVisualStyleBackColor = true;
			this->prevSong->Click += gcnew System::EventHandler(this, &MyForm::prevSong_Click);
			// 
			// nextSong
			// 
			this->nextSong->Location = System::Drawing::Point(377, 224);
			this->nextSong->Name = L"nextSong";
			this->nextSong->Size = System::Drawing::Size(50, 50);
			this->nextSong->TabIndex = 5;
			this->nextSong->Text = L"next";
			this->nextSong->UseVisualStyleBackColor = true;
			this->nextSong->Click += gcnew System::EventHandler(this, &MyForm::nextSong_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(480, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 296);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->nextSong);
			this->Controls->Add(this->prevSong);
			this->Controls->Add(this->pausePlay);
			this->Controls->Add(this->trackBar);
			this->Controls->Add(this->volumeBar);
			this->Controls->Add(this->songName);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void pausePlay_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void nextSong_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void prevSong_Click(System::Object^  sender, System::EventArgs^  e) {

}
};
}
