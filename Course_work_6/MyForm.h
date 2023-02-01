#pragma once
#include "MyForm1.h"
#include <math.h>
#include <cstdlib>

namespace Coursework6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			groupBox1->Hide();
			groupBox2->Hide();
			groupBox3->Hide();
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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ восстановитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ инструментыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ фильтр1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ фильтр2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ фильтр3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ фильтр4ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ фильтр5ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ видToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ увеличитьМасштабToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ уменьшитьМасштабToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->восстановитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->инструментыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->фильтр1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->фильтр2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->фильтр3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->фильтр4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->фильтр5ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->видToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->увеличитьМасштабToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->уменьшитьМасштабToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->файлToolStripMenuItem,
					this->инструментыToolStripMenuItem, this->видToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1206, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->открытьToolStripMenuItem,
					this->сохранитьToolStripMenuItem, this->восстановитьToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripMenuItem_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripMenuItem_Click);
			// 
			// восстановитьToolStripMenuItem
			// 
			this->восстановитьToolStripMenuItem->Name = L"восстановитьToolStripMenuItem";
			this->восстановитьToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->восстановитьToolStripMenuItem->Text = L"Восстановить";
			this->восстановитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::восстановитьToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// инструментыToolStripMenuItem
			// 
			this->инструментыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->фильтр1ToolStripMenuItem,
					this->фильтр2ToolStripMenuItem, this->фильтр3ToolStripMenuItem, this->фильтр4ToolStripMenuItem, this->фильтр5ToolStripMenuItem
			});
			this->инструментыToolStripMenuItem->Name = L"инструментыToolStripMenuItem";
			this->инструментыToolStripMenuItem->Size = System::Drawing::Size(95, 20);
			this->инструментыToolStripMenuItem->Text = L"Инструменты";
			// 
			// фильтр1ToolStripMenuItem
			// 
			this->фильтр1ToolStripMenuItem->Name = L"фильтр1ToolStripMenuItem";
			this->фильтр1ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->фильтр1ToolStripMenuItem->Text = L"Фильтр 1";
			this->фильтр1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::фильтр1ToolStripMenuItem_Click);
			// 
			// фильтр2ToolStripMenuItem
			// 
			this->фильтр2ToolStripMenuItem->Name = L"фильтр2ToolStripMenuItem";
			this->фильтр2ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->фильтр2ToolStripMenuItem->Text = L"Фильтр 2";
			this->фильтр2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::фильтр2ToolStripMenuItem_Click);
			// 
			// фильтр3ToolStripMenuItem
			// 
			this->фильтр3ToolStripMenuItem->Name = L"фильтр3ToolStripMenuItem";
			this->фильтр3ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->фильтр3ToolStripMenuItem->Text = L"Фильтр 3";
			this->фильтр3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::фильтр3ToolStripMenuItem_Click);
			// 
			// фильтр4ToolStripMenuItem
			// 
			this->фильтр4ToolStripMenuItem->Name = L"фильтр4ToolStripMenuItem";
			this->фильтр4ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->фильтр4ToolStripMenuItem->Text = L"Фильтр 4";
			this->фильтр4ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::фильтр4ToolStripMenuItem_Click);
			// 
			// фильтр5ToolStripMenuItem
			// 
			this->фильтр5ToolStripMenuItem->Name = L"фильтр5ToolStripMenuItem";
			this->фильтр5ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->фильтр5ToolStripMenuItem->Text = L"Фильтр 5";
			this->фильтр5ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::фильтр5ToolStripMenuItem_Click);
			// 
			// видToolStripMenuItem
			// 
			this->видToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->увеличитьМасштабToolStripMenuItem,
					this->уменьшитьМасштабToolStripMenuItem
			});
			this->видToolStripMenuItem->Name = L"видToolStripMenuItem";
			this->видToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->видToolStripMenuItem->Text = L"Вид";
			// 
			// увеличитьМасштабToolStripMenuItem
			// 
			this->увеличитьМасштабToolStripMenuItem->Name = L"увеличитьМасштабToolStripMenuItem";
			this->увеличитьМасштабToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->увеличитьМасштабToolStripMenuItem->Text = L"Увеличить масштаб";
			this->увеличитьМасштабToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::увеличитьМасштабToolStripMenuItem_Click);
			// 
			// уменьшитьМасштабToolStripMenuItem
			// 
			this->уменьшитьМасштабToolStripMenuItem->Name = L"уменьшитьМасштабToolStripMenuItem";
			this->уменьшитьМасштабToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->уменьшитьМасштабToolStripMenuItem->Text = L"Уменьшить масштаб";
			this->уменьшитьМасштабToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::уменьшитьМасштабToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::справкаToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(12, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(581, 441);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(578, 438);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 483);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Size";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(67, 483);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(15, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"x:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(88, 483);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(155, 483);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"y:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(176, 483);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(236, 483);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"R:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(260, 483);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(314, 483);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"G:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(338, 483);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 13);
			this->label9->TabIndex = 10;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(398, 483);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 13);
			this->label10->TabIndex = 11;
			this->label10->Text = L"B:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(421, 483);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 12;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(599, 365);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(53, 13);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Масштаб";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(477, 483);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(214, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"Применить к половине изображения";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckStateChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckStateChanged);
			// 
			// chart1
			// 
			chartArea1->AxisX->Title = L"Яркость";
			chartArea1->AxisY->Title = L"Количество пикселей";
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(6, 19);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(442, 209);
			this->chart1->TabIndex = 15;
			this->chart1->Text = L"chart1";
			// 
			// chart2
			// 
			chartArea2->AxisX->Title = L"Яркость";
			chartArea2->AxisY->Title = L"Количество пикселей";
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(6, 259);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"2";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(442, 210);
			this->chart2->TabIndex = 16;
			this->chart2->Text = L"chart2";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(596, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(144, 157);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Введите значения q1 и q2 (q2>q1)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(6, 96);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(19, 13);
			this->label14->TabIndex = 4;
			this->label14->Text = L"q2";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 56);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(19, 13);
			this->label13->TabIndex = 3;
			this->label13->Text = L"q1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 128);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Подтвердить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(38, 93);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(38, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(599, 190);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(141, 154);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Введите коэффициент уменьшения масштаба (целое положительное число)";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(16, 70);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(119, 20);
			this->textBox3->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(26, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Подтвердить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->chart1);
			this->groupBox3->Controls->Add(this->chart2);
			this->groupBox3->Location = System::Drawing::Point(746, 27);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(452, 476);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Растяжка гистограммы";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(102, 230);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(197, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Выполнить растяжку";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1206, 515);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox3);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Редактор изображений";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:	System::Void stretchHistogram(List<int>% pdata, int width, int height, int max_val)
		{
			int total = width * height;

			//Находим минимальное и максимальное значения яркости исходной картинки
			int max = 0;
			int min = 255;
			for (int i = 0; i < total; i++)
			{
				if (pdata[i] > max) max = pdata[i];
				if (pdata[i] < min) min = pdata[i];
			}

			// Вычисляем коэффициенты для формулы g(x,y) = a*f(x,y) + b
			float a = 255 / (max - min);
			float b = 255 - a * max;

			// Пересчитываем значения яркости пикселей
			for (int i = 0; i < total; i++) {
				int new_value = a * pdata[i] + b;
				if (new_value <= 255 && new_value >= 0)
				{
					pdata[i] = new_value;
				}
				else if (new_value < 0)
				{
					pdata[i] = 0;
				}
				else
				{
					pdata[i] = 255;
				}
			}
		}

		Bitmap^ img1;
		Bitmap^ baseImage;
		bool imageUploaded = 0, filterFourActivated = 0, filterThreeActivated = 0, checkedFlag = 0;
		int halfOfThePicture = 0, ScaleCounter = 100;
		double gamma = 1;
		int scaleFilter5 = 100, q1, q2;
		double scale = 1;
		int operationNum;
		List<int> Gist;
		List<int> stretchedGist;
		List<int> pdata;
		List<int> stretchedPdata;

		// Открыть
private: System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Сохранить
private: System::Void сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Восстановить
private: System::Void восстановитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Выход
private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Увеличить масштаб
private: System::Void увеличитьМасштабToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Уменьшить масштаб
private: System::Void уменьшитьМасштабToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Справка
private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Фильтр 1.3 Инверсия
private: System::Void фильтр1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Фильтр 2.6 линейное изменение яркости
private: System::Void фильтр2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   // Нажатие кнопки "Подтвердить" в groupBox1
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	   //Фильтр 3.3 Поворот изображения на 180 градусов
private: System::Void фильтр3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Фильтр 4.2 Линейная растяжка гистограммы
private: System::Void фильтр4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //Выполнить растяжку
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	   //Фильтр 5.6 увеличение масштаба изображения методом линейной интерполяции
private: System::Void фильтр5ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   // Кнопка "Подтвердить" в groupBox2
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	   // Если мы перемещаем мышью по pictureBox1
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	// Применить к половине изображения
	// Изменение нажатия checkBox
private: System::Void checkBox1_CheckStateChanged(System::Object^ sender, System::EventArgs^ e);
};
}
