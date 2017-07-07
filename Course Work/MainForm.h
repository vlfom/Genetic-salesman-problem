//
// MenuForm.h
//

#pragma once

#include "path_hash.h"
#include "GeneticSalesman.h"
#include "AlgoOptionsForm.h"
#include <algorithm>
#include <fstream>
#include <omp.h>

namespace CourseWork {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: GeneticSalesman *problem;
	private: std::vector < EvolutionIt > *mutationList;

	private: int individualsNumV = 100;
	private: int mutationNumV1 = 5, mutationNumV2 = 5, mutationNumV3 = 5, mutationNumV4 = 5;
	private: int mutationProbV = 3;
	private: int breedingNumV1 = 5, breedingNumV2 = 5, breedingNumV3 = 5;

	private: double startTime;
	private: double pauseTime;
	private: int iterationsCount;

	public: AlgoOptions ^algoOptions;

	private: bool timerOn;

	private: System::Windows::Forms::Timer^  timer;

	private: System::Windows::Forms::Button^  btn_start;
	private: System::Windows::Forms::Button^  btn_pause;
	private: System::Windows::Forms::Button^  btn_continue;
	private: System::Windows::Forms::Button^  btn_reset;
	private: System::Windows::Forms::Button^  btn_clear;
	private: System::Windows::Forms::Button^  btn_openFile;
	private: System::Windows::Forms::Button^  btn_saveFile;
	private: System::Windows::Forms::Button^  btn_algo_opts;
	private: System::Windows::Forms::Button^  btn_returnToMain;

	private: System::Windows::Forms::Label^  iterationsNumberDesc;
	private: System::Windows::Forms::Label^  elapsedTimeDesc;
	private: System::Windows::Forms::Label^  iterationsNumberVal;

	private: System::Windows::Forms::Label^  elapsedTimeVal;
	private: System::Windows::Forms::Label^  pathLengthVal;
	private: System::Windows::Forms::Label^  pathLengthDesc;

	private: System::Windows::Forms::Label^  labelDescBigField;
	private: System::Windows::Forms::Label^  labelDescSmallFields;
	private: System::Windows::Forms::GroupBox^  controlsGroup;

	private: System::Windows::Forms::GroupBox^  mutationHistoryGroup;
	private: System::Windows::Forms::GroupBox^  infoGroup;

	private: System::Windows::Forms::GroupBox^  workWithGraphGroup;

	private: System::Windows::Forms::PictureBox^  bigGraphField;
	private: System::Windows::Forms::PictureBox^  smallGraphField1;
	private: System::Windows::Forms::PictureBox^  smallGraphField2;

	private: System::Windows::Forms::ListBox^  mutationListBox;

	private:
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->bigGraphField = (gcnew System::Windows::Forms::PictureBox());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_openFile = (gcnew System::Windows::Forms::Button());
			this->btn_clear = (gcnew System::Windows::Forms::Button());
			this->btn_pause = (gcnew System::Windows::Forms::Button());
			this->btn_continue = (gcnew System::Windows::Forms::Button());
			this->iterationsNumberDesc = (gcnew System::Windows::Forms::Label());
			this->elapsedTimeDesc = (gcnew System::Windows::Forms::Label());
			this->iterationsNumberVal = (gcnew System::Windows::Forms::Label());
			this->elapsedTimeVal = (gcnew System::Windows::Forms::Label());
			this->pathLengthVal = (gcnew System::Windows::Forms::Label());
			this->pathLengthDesc = (gcnew System::Windows::Forms::Label());
			this->controlsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->btn_algo_opts = (gcnew System::Windows::Forms::Button());
			this->btn_saveFile = (gcnew System::Windows::Forms::Button());
			this->smallGraphField1 = (gcnew System::Windows::Forms::PictureBox());
			this->smallGraphField2 = (gcnew System::Windows::Forms::PictureBox());
			this->mutationListBox = (gcnew System::Windows::Forms::ListBox());
			this->mutationHistoryGroup = (gcnew System::Windows::Forms::GroupBox());
			this->labelDescBigField = (gcnew System::Windows::Forms::Label());
			this->labelDescSmallFields = (gcnew System::Windows::Forms::Label());
			this->infoGroup = (gcnew System::Windows::Forms::GroupBox());
			this->btn_returnToMain = (gcnew System::Windows::Forms::Button());
			this->workWithGraphGroup = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bigGraphField))->BeginInit();
			this->controlsGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->smallGraphField1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->smallGraphField2))->BeginInit();
			this->mutationHistoryGroup->SuspendLayout();
			this->infoGroup->SuspendLayout();
			this->workWithGraphGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_start
			// 
			this->btn_start->Location = System::Drawing::Point(10, 22);
			this->btn_start->Margin = System::Windows::Forms::Padding(2);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(145, 32);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"Start solving";
			this->btn_start->UseVisualStyleBackColor = true;
			this->btn_start->Click += gcnew System::EventHandler(this, &MyForm::btn_start_Click);
			// 
			// bigGraphField
			// 
			this->bigGraphField->Location = System::Drawing::Point(11, 23);
			this->bigGraphField->Margin = System::Windows::Forms::Padding(2);
			this->bigGraphField->Name = L"bigGraphField";
			this->bigGraphField->Size = System::Drawing::Size(533, 520);
			this->bigGraphField->TabIndex = 1;
			this->bigGraphField->TabStop = false;
			this->bigGraphField->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::bigGraphField_MouseClick);
			// 
			// btn_reset
			// 
			this->btn_reset->Location = System::Drawing::Point(10, 58);
			this->btn_reset->Margin = System::Windows::Forms::Padding(2);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(145, 32);
			this->btn_reset->TabIndex = 2;
			this->btn_reset->Text = L"Stop solving";
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Click += gcnew System::EventHandler(this, &MyForm::btn_reset_Click);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// btn_openFile
			// 
			this->btn_openFile->Location = System::Drawing::Point(9, 59);
			this->btn_openFile->Margin = System::Windows::Forms::Padding(2);
			this->btn_openFile->Name = L"btn_openFile";
			this->btn_openFile->Size = System::Drawing::Size(323, 32);
			this->btn_openFile->TabIndex = 3;
			this->btn_openFile->Text = L"Open graph from file";
			this->btn_openFile->UseVisualStyleBackColor = true;
			this->btn_openFile->Click += gcnew System::EventHandler(this, &MyForm::btn_openFile_Click);
			// 
			// btn_clear
			// 
			this->btn_clear->Location = System::Drawing::Point(9, 20);
			this->btn_clear->Margin = System::Windows::Forms::Padding(2);
			this->btn_clear->Name = L"btn_clear";
			this->btn_clear->Size = System::Drawing::Size(323, 32);
			this->btn_clear->TabIndex = 4;
			this->btn_clear->Text = L"Clear field";
			this->btn_clear->UseVisualStyleBackColor = true;
			this->btn_clear->Click += gcnew System::EventHandler(this, &MyForm::btn_clear_Click);
			// 
			// btn_pause
			// 
			this->btn_pause->Location = System::Drawing::Point(10, 21);
			this->btn_pause->Margin = System::Windows::Forms::Padding(2);
			this->btn_pause->Name = L"btn_pause";
			this->btn_pause->Size = System::Drawing::Size(145, 32);
			this->btn_pause->TabIndex = 5;
			this->btn_pause->Text = L"Pause";
			this->btn_pause->UseVisualStyleBackColor = true;
			this->btn_pause->Visible = false;
			this->btn_pause->Click += gcnew System::EventHandler(this, &MyForm::btn_pause_Click);
			// 
			// btn_continue
			// 
			this->btn_continue->Location = System::Drawing::Point(10, 21);
			this->btn_continue->Margin = System::Windows::Forms::Padding(2);
			this->btn_continue->Name = L"btn_continue";
			this->btn_continue->Size = System::Drawing::Size(145, 32);
			this->btn_continue->TabIndex = 6;
			this->btn_continue->Text = L"Continue solving";
			this->btn_continue->UseVisualStyleBackColor = true;
			this->btn_continue->Visible = false;
			this->btn_continue->Click += gcnew System::EventHandler(this, &MyForm::btn_continue_Click);
			// 
			// iterationsNumberDesc
			// 
			this->iterationsNumberDesc->AutoSize = true;
			this->iterationsNumberDesc->Location = System::Drawing::Point(30, 22);
			this->iterationsNumberDesc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->iterationsNumberDesc->Name = L"iterationsNumberDesc";
			this->iterationsNumberDesc->Size = System::Drawing::Size(86, 13);
			this->iterationsNumberDesc->TabIndex = 17;
			this->iterationsNumberDesc->Text = L"Iteration number:";
			// 
			// elapsedTimeDesc
			// 
			this->elapsedTimeDesc->AutoSize = true;
			this->elapsedTimeDesc->Location = System::Drawing::Point(167, 22);
			this->elapsedTimeDesc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->elapsedTimeDesc->Name = L"elapsedTimeDesc";
			this->elapsedTimeDesc->Size = System::Drawing::Size(73, 13);
			this->elapsedTimeDesc->TabIndex = 18;
			this->elapsedTimeDesc->Text = L"Time elapsed:";
			// 
			// iterationsNumberVal
			// 
			this->iterationsNumberVal->AutoSize = true;
			this->iterationsNumberVal->Location = System::Drawing::Point(117, 22);
			this->iterationsNumberVal->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->iterationsNumberVal->Name = L"iterationsNumberVal";
			this->iterationsNumberVal->Size = System::Drawing::Size(13, 13);
			this->iterationsNumberVal->TabIndex = 19;
			this->iterationsNumberVal->Text = L"0";
			// 
			// elapsedTimeVal
			// 
			this->elapsedTimeVal->AutoSize = true;
			this->elapsedTimeVal->Location = System::Drawing::Point(242, 23);
			this->elapsedTimeVal->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->elapsedTimeVal->Name = L"elapsedTimeVal";
			this->elapsedTimeVal->Size = System::Drawing::Size(13, 13);
			this->elapsedTimeVal->TabIndex = 20;
			this->elapsedTimeVal->Text = L"0";
			// 
			// pathLengthVal
			// 
			this->pathLengthVal->AutoSize = true;
			this->pathLengthVal->Location = System::Drawing::Point(449, 22);
			this->pathLengthVal->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pathLengthVal->Name = L"pathLengthVal";
			this->pathLengthVal->Size = System::Drawing::Size(13, 13);
			this->pathLengthVal->TabIndex = 22;
			this->pathLengthVal->Text = L"0";
			// 
			// pathLengthDesc
			// 
			this->pathLengthDesc->AutoSize = true;
			this->pathLengthDesc->Location = System::Drawing::Point(306, 22);
			this->pathLengthDesc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pathLengthDesc->Name = L"pathLengthDesc";
			this->pathLengthDesc->Size = System::Drawing::Size(138, 13);
			this->pathLengthDesc->TabIndex = 21;
			this->pathLengthDesc->Text = L"Length of current best path:";
			// 
			// controlsGroup
			// 
			this->controlsGroup->Controls->Add(this->btn_algo_opts);
			this->controlsGroup->Controls->Add(this->btn_start);
			this->controlsGroup->Controls->Add(this->btn_reset);
			this->controlsGroup->Controls->Add(this->btn_continue);
			this->controlsGroup->Controls->Add(this->btn_pause);
			this->controlsGroup->Location = System::Drawing::Point(733, 194);
			this->controlsGroup->Margin = System::Windows::Forms::Padding(2);
			this->controlsGroup->Name = L"controlsGroup";
			this->controlsGroup->Padding = System::Windows::Forms::Padding(2);
			this->controlsGroup->Size = System::Drawing::Size(167, 153);
			this->controlsGroup->TabIndex = 23;
			this->controlsGroup->TabStop = false;
			this->controlsGroup->Text = L"Controls panel";
			// 
			// btn_algo_opts
			// 
			this->btn_algo_opts->Location = System::Drawing::Point(10, 108);
			this->btn_algo_opts->Margin = System::Windows::Forms::Padding(2);
			this->btn_algo_opts->Name = L"btn_algo_opts";
			this->btn_algo_opts->Size = System::Drawing::Size(145, 32);
			this->btn_algo_opts->TabIndex = 28;
			this->btn_algo_opts->Text = L"Algorithm parameters";
			this->btn_algo_opts->UseVisualStyleBackColor = true;
			this->btn_algo_opts->Click += gcnew System::EventHandler(this, &MyForm::btn_algo_opts_Click);
			// 
			// btn_saveFile
			// 
			this->btn_saveFile->Location = System::Drawing::Point(9, 95);
			this->btn_saveFile->Margin = System::Windows::Forms::Padding(2);
			this->btn_saveFile->Name = L"btn_saveFile";
			this->btn_saveFile->Size = System::Drawing::Size(323, 32);
			this->btn_saveFile->TabIndex = 27;
			this->btn_saveFile->Text = L"Save graph to file";
			this->btn_saveFile->UseVisualStyleBackColor = true;
			this->btn_saveFile->Click += gcnew System::EventHandler(this, &MyForm::btn_saveFile_Click);
			// 
			// smallGraphField1
			// 
			this->smallGraphField1->Location = System::Drawing::Point(554, 23);
			this->smallGraphField1->Margin = System::Windows::Forms::Padding(2);
			this->smallGraphField1->Name = L"smallGraphField1";
			this->smallGraphField1->Size = System::Drawing::Size(167, 162);
			this->smallGraphField1->TabIndex = 29;
			this->smallGraphField1->TabStop = false;
			// 
			// smallGraphField2
			// 
			this->smallGraphField2->Location = System::Drawing::Point(733, 22);
			this->smallGraphField2->Margin = System::Windows::Forms::Padding(2);
			this->smallGraphField2->Name = L"smallGraphField2";
			this->smallGraphField2->Size = System::Drawing::Size(167, 162);
			this->smallGraphField2->TabIndex = 30;
			this->smallGraphField2->TabStop = false;
			// 
			// mutationListBox
			// 
			this->mutationListBox->FormattingEnabled = true;
			this->mutationListBox->Location = System::Drawing::Point(10, 19);
			this->mutationListBox->Margin = System::Windows::Forms::Padding(2);
			this->mutationListBox->Name = L"mutationListBox";
			this->mutationListBox->Size = System::Drawing::Size(146, 186);
			this->mutationListBox->TabIndex = 31;
			this->mutationListBox->DoubleClick += gcnew System::EventHandler(this, &MyForm::mutationListBox_DoubleClick);
			// 
			// mutationHistoryGroup
			// 
			this->mutationHistoryGroup->Controls->Add(this->mutationListBox);
			this->mutationHistoryGroup->Location = System::Drawing::Point(554, 194);
			this->mutationHistoryGroup->Margin = System::Windows::Forms::Padding(2);
			this->mutationHistoryGroup->Name = L"mutationHistoryGroup";
			this->mutationHistoryGroup->Padding = System::Windows::Forms::Padding(2);
			this->mutationHistoryGroup->Size = System::Drawing::Size(167, 213);
			this->mutationHistoryGroup->TabIndex = 32;
			this->mutationHistoryGroup->TabStop = false;
			this->mutationHistoryGroup->Text = L"History of best mutations";
			// 
			// labelDescBigField
			// 
			this->labelDescBigField->AutoSize = true;
			this->labelDescBigField->Location = System::Drawing::Point(8, 5);
			this->labelDescBigField->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelDescBigField->Name = L"labelDescBigField";
			this->labelDescBigField->Size = System::Drawing::Size(58, 13);
			this->labelDescBigField->TabIndex = 33;
			this->labelDescBigField->Text = L"Graph field";
			// 
			// labelDescSmallFields
			// 
			this->labelDescSmallFields->AutoSize = true;
			this->labelDescSmallFields->Location = System::Drawing::Point(551, 5);
			this->labelDescSmallFields->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelDescSmallFields->Name = L"labelDescSmallFields";
			this->labelDescSmallFields->Size = System::Drawing::Size(159, 13);
			this->labelDescSmallFields->TabIndex = 34;
			this->labelDescSmallFields->Text = L"Ancestors of best representative";
			// 
			// infoGroup
			// 
			this->infoGroup->Controls->Add(this->pathLengthVal);
			this->infoGroup->Controls->Add(this->pathLengthDesc);
			this->infoGroup->Controls->Add(this->elapsedTimeVal);
			this->infoGroup->Controls->Add(this->iterationsNumberVal);
			this->infoGroup->Controls->Add(this->elapsedTimeDesc);
			this->infoGroup->Controls->Add(this->iterationsNumberDesc);
			this->infoGroup->Location = System::Drawing::Point(11, 549);
			this->infoGroup->Margin = System::Windows::Forms::Padding(2);
			this->infoGroup->Name = L"infoGroup";
			this->infoGroup->Padding = System::Windows::Forms::Padding(2);
			this->infoGroup->Size = System::Drawing::Size(533, 44);
			this->infoGroup->TabIndex = 35;
			this->infoGroup->TabStop = false;
			this->infoGroup->Text = L"Solution status";
			// 
			// btn_returnToMain
			// 
			this->btn_returnToMain->Location = System::Drawing::Point(555, 554);
			this->btn_returnToMain->Margin = System::Windows::Forms::Padding(2);
			this->btn_returnToMain->Name = L"btn_returnToMain";
			this->btn_returnToMain->Size = System::Drawing::Size(344, 38);
			this->btn_returnToMain->TabIndex = 36;
			this->btn_returnToMain->Text = L"Return to the main menu";
			this->btn_returnToMain->UseVisualStyleBackColor = true;
			this->btn_returnToMain->Click += gcnew System::EventHandler(this, &MyForm::btn_returnToMain_Click);
			// 
			// workWithGraphGroup
			// 
			this->workWithGraphGroup->Controls->Add(this->btn_saveFile);
			this->workWithGraphGroup->Controls->Add(this->btn_openFile);
			this->workWithGraphGroup->Controls->Add(this->btn_clear);
			this->workWithGraphGroup->Location = System::Drawing::Point(555, 411);
			this->workWithGraphGroup->Margin = System::Windows::Forms::Padding(2);
			this->workWithGraphGroup->Name = L"workWithGraphGroup";
			this->workWithGraphGroup->Padding = System::Windows::Forms::Padding(2);
			this->workWithGraphGroup->Size = System::Drawing::Size(344, 135);
			this->workWithGraphGroup->TabIndex = 37;
			this->workWithGraphGroup->TabStop = false;
			this->workWithGraphGroup->Text = L"Field controls";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(881, 601);
			this->ControlBox = false;
			this->Controls->Add(this->workWithGraphGroup);
			this->Controls->Add(this->btn_returnToMain);
			this->Controls->Add(this->infoGroup);
			this->Controls->Add(this->labelDescSmallFields);
			this->Controls->Add(this->labelDescBigField);
			this->Controls->Add(this->mutationHistoryGroup);
			this->Controls->Add(this->smallGraphField2);
			this->Controls->Add(this->smallGraphField1);
			this->Controls->Add(this->controlsGroup);
			this->Controls->Add(this->bigGraphField);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Traveling Salesman Problem";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bigGraphField))->EndInit();
			this->controlsGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->smallGraphField1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->smallGraphField2))->EndInit();
			this->mutationHistoryGroup->ResumeLayout(false);
			this->infoGroup->ResumeLayout(false);
			this->infoGroup->PerformLayout();
			this->workWithGraphGroup->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics ^ clearWithBorder(PictureBox ^ pictureBox) {
		int w = pictureBox->Width;
		int h = pictureBox->Height;
		pictureBox->Image = gcnew Bitmap(w, h);
		Graphics ^ g = Graphics::FromImage(pictureBox->Image);

		Brush ^ bsh = gcnew SolidBrush(Color::White);
		g->FillRectangle(bsh, 0, 0, w, h);
		Brush ^ bshG = gcnew SolidBrush(Color::Green);
		Pen ^ pn2 = gcnew Pen(Color::LightSteelBlue, 2);
		g->DrawRectangle(pn2, 1, 1, w - 2, h - 2);
		return g;
	}

	private: void drawNodes(Graphics ^ g, float size) {
		float border = 2;
		float diameter = 0.02;

		size -= 0.5 * diameter * size;
		size -= 2 * border;

		float sizeY = size * 0.95;

		size *= 0.98;

		Pen ^ pn = gcnew Pen(Color::Black);
		if (size > 200) {
			HatchBrush^ hBrush = gcnew HatchBrush(HatchStyle::DarkDownwardDiagonal, Color::White, Color::Blue);
			for (int i = 0; i < problem->nodes.size(); ++i){
				g->FillEllipse(
					hBrush,
					border + (diameter / 2 + problem->nodes[i].first - diameter / 2) * size,
					border + (diameter / 2 + problem->nodes[i].second - diameter / 2) * sizeY,
					diameter * size, diameter * size
					);
				g->DrawEllipse(
					pn,
					border + (diameter / 2 + problem->nodes[i].first - diameter / 2) * size,
					border + (diameter / 2 + problem->nodes[i].second - diameter / 2) * sizeY,
					diameter * size, diameter * size
					);
			}
		}
		else {
			Brush^ brush = gcnew SolidBrush(Color::Blue);
			for (int i = 0; i < problem->nodes.size(); ++i){
				g->FillEllipse(
					brush,
					border + (diameter / 2 + problem->nodes[i].first - diameter / 2) * size,
					border + (diameter / 2 + problem->nodes[i].second - diameter / 2) * sizeY,
					diameter * size, diameter * size
					);
				g->DrawEllipse(
					pn,
					border + (diameter / 2 + problem->nodes[i].first - diameter / 2) * size,
					border + (diameter / 2 + problem->nodes[i].second - diameter / 2) * sizeY,
					diameter * size, diameter * size
					);
			}
		}
	}

	private: void drawEdges(Graphics ^ g, vector < int > order, set < pair < int, int > > badEdges, float size, int color) {
		float border = 2;
		float diameter = 0.02;

		size -= 0.5 * diameter * size;
		size -= 2 * border;

		float sizeY = size * 0.95;

		size *= 0.98;

		Pen ^pn,
			^pnN,
			^pnA = gcnew Pen(Color::Red);
		if (color == 0)
			pnN = gcnew Pen(Color::Black, 0.1);
		else if (color == 1)
			pnN = gcnew Pen(Color::Gray, 0.1);
		for (int i = 0; i < problem->nodes.size(); ++i) {
			int next = (i + 1) % (int)problem->nodes.size();

			if (!badEdges.count(make_pair(i, next)))
				pn = pnN;
			else
				pn = pnA;

			g->DrawLine(
				pn,
				border + (problem->nodes[order[i]].first + diameter / 2) * size,
				border + (problem->nodes[order[i]].second + diameter / 2) * sizeY,
				border + (problem->nodes[order[next]].first + diameter / 2) * size,
				border + (problem->nodes[order[next]].second + diameter / 2) * sizeY
				);
		}
	}

	private: System::Void btn_start_Click(System::Object^  sender, System::EventArgs^  e) {
		individualsNumV = Convert::ToInt32(algoOptions->individNum->Value);

		if (problem->nodes.size() < 10) {
			MessageBox::Show(L"Граф должен содержать хотя бы 10 вершин", "Notification", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			return;
		}

		timerOn = true;

		mutationListBox->Enabled = false;
		btn_returnToMain->Enabled = false;
		btn_clear->Enabled = false;
		btn_saveFile->Enabled = false;
		btn_openFile->Enabled = false;

		problem->generateStartPopulation(individualsNumV);

		startTime = omp_get_wtime();
		timer->Interval = 100;
		timer->Start();

		btn_start->Visible = false;
		btn_pause->Visible = true;

		clearWithBorder(smallGraphField1);
		clearWithBorder(smallGraphField2);
	}

	private: System::Void btn_pause_Click(System::Object^  sender, System::EventArgs^  e) {
		pauseTime = omp_get_wtime();

		timer->Stop();

		mutationListBox->Enabled = true;
		btn_pause->Visible = false;
		btn_continue->Visible = true;
	}

	private: System::Void btn_continue_Click(System::Object^  sender, System::EventArgs^  e) {
		startTime += omp_get_wtime() - pauseTime;

		timer->Start();

		mutationListBox->ClearSelected();
		mutationListBox->Enabled = false;
		btn_continue->Visible = false;
		btn_pause->Visible = true;
	}

	private: System::Void bigGraphField_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)  {
		if (timerOn)
			return;

		problem->addNode(e->X * 1.0 / bigGraphField->Width, e->Y * 1.0 / bigGraphField->Height);

		Graphics ^ g = clearWithBorder(bigGraphField);
		drawNodes(Graphics::FromImage(bigGraphField->Image), bigGraphField->Width);
	}

	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		/* Algorithm iteration */
		individualsNumV = Convert::ToInt32(algoOptions->individNum->Value);
		mutationProbV = Convert::ToInt32(algoOptions->mutationProb->Value);

		mutationNumV1 = Convert::ToInt32(algoOptions->mutationNum1->Value);
		mutationNumV2 = Convert::ToInt32(algoOptions->mutationNum2->Value);
		mutationNumV3 = Convert::ToInt32(algoOptions->mutationNum3->Value);
		mutationNumV4 = Convert::ToInt32(algoOptions->mutationNum4->Value);

		breedingNumV1 = Convert::ToInt32(algoOptions->breedingNum1->Value);
		breedingNumV2 = Convert::ToInt32(algoOptions->breedingNum2->Value);
		breedingNumV3 = Convert::ToInt32(algoOptions->breedingNum3->Value);

		double *breedingPriority = new double[3] { 0, 0, 0 };
		int breedingPrioritySum =
			breedingNumV1 +
			breedingNumV2 +
			breedingNumV3;
		if (breedingPrioritySum)
			breedingPriority[0] = breedingNumV1 * 1.0 / breedingPrioritySum;
		breedingPrioritySum -= breedingNumV1;
		if (breedingPrioritySum)
			breedingPriority[1] = breedingNumV2 * 1.0 / breedingPrioritySum;
		breedingPriority[2] = 1;

		double *mutationPriority = new double[4] { 0, 0, 0, 0 };
		int mutationPrioritySum =
			mutationNumV1 +
			mutationNumV2 +
			mutationNumV3 +
			mutationNumV4;
		if (mutationPrioritySum)
			mutationPriority[0] = mutationNumV1 * 1.0 / mutationPrioritySum;
		mutationPrioritySum -= mutationNumV1;
		if (mutationPrioritySum)
			mutationPriority[1] = mutationNumV2 * 1.0 / mutationPrioritySum;
		mutationPrioritySum -= mutationNumV2;
		if (mutationPrioritySum)
			mutationPriority[2] = mutationNumV3 * 1.0 / mutationPrioritySum;
		mutationPrioritySum -= mutationNumV3;
		if (mutationPrioritySum)
			mutationPriority[3] = mutationNumV4 * 1.0 / mutationPrioritySum;

		EvolutionIt getIteration =
			problem->evolutionIteration(breedingPriority, mutationProbV * 0.01, mutationPriority);

		std::sort(problem->individuals.begin(), problem->individuals.end());

		/* Visualisation */
		Graphics ^ g = clearWithBorder(bigGraphField);
		drawEdges(g, problem->individuals[0].second, set < pair < int, int > >(), bigGraphField->Width, 0);
		drawNodes(g, bigGraphField->Width);

		if (getIteration.gotBetter) {
			mutationList->push_back(getIteration);
			mutationListBox->Items->Add(" " + Convert::ToString(iterationsCount) + L"  iteration");

			Graphics ^ g2 = clearWithBorder(smallGraphField1);
			drawEdges(g2, getIteration.par1, getIteration.diff1, smallGraphField1->Width, 1);
			drawNodes(g2, smallGraphField1->Width);

			Graphics ^ g3 = clearWithBorder(smallGraphField2);
			drawEdges(g3, getIteration.par2, getIteration.diff2, smallGraphField2->Width, 1);
			drawNodes(g3, smallGraphField2->Width);
		}

		/* Updating labels */
		double elapsedTime = omp_get_wtime() - startTime;
		iterationsCount++;
		elapsedTimeVal->Text = ((int)elapsedTime).ToString() + "." + ((int)((elapsedTime - (int)elapsedTime) * 100)).ToString() + " s";
		iterationsNumberVal->Text = iterationsCount.ToString();
		pathLengthVal->Text = Convert::ToString((long)(problem->individuals.front().first * 1000) * 0.001);
	}

	private: System::Void btn_reset_Click(System::Object^  sender, System::EventArgs^  e) {
		timerOn = false;

		iterationsCount = 0;

		mutationListBox->Enabled = true;
		btn_returnToMain->Enabled = true;
		btn_clear->Enabled = true;
		btn_saveFile->Enabled = true;
		btn_openFile->Enabled = true;
		elapsedTimeVal->Text = "0";
		iterationsNumberVal->Text = "0";
		pathLengthVal->Text = "0";
		mutationListBox->ClearSelected();
		mutationListBox->Items->Clear();
		mutationList->clear();

		timer->Stop();
		btn_continue->Visible = false;
		btn_pause->Visible = false;
		btn_start->Visible = true;

		timer->Stop();
		problem->individuals.clear();
		problem->individualsHash.clear();

		Graphics ^ g = clearWithBorder(bigGraphField);
		drawNodes(Graphics::FromImage(bigGraphField->Image), bigGraphField->Width);

		clearWithBorder(smallGraphField1);
		clearWithBorder(smallGraphField2);
	}

	private: System::Void btn_clear_Click(System::Object^  sender, System::EventArgs^  e) {
		timerOn = false;

		iterationsCount = 0;

		mutationListBox->Enabled = true;
		btn_returnToMain->Enabled = true;
		btn_clear->Enabled = true;
		btn_saveFile->Enabled = true;
		btn_openFile->Enabled = true;
		elapsedTimeVal->Text = "0";
		iterationsNumberVal->Text = "0";
		pathLengthVal->Text = "0";
		mutationListBox->ClearSelected();
		mutationListBox->Items->Clear();
		mutationList->clear();

		timer->Stop();
		btn_continue->Visible = false;
		btn_pause->Visible = false;
		btn_start->Visible = true;

		problem = new GeneticSalesman();

		Graphics ^ g = clearWithBorder(bigGraphField);
		drawNodes(Graphics::FromImage(bigGraphField->Image), bigGraphField->Width);

		clearWithBorder(smallGraphField1);
		clearWithBorder(smallGraphField2);
	}

	private: System::Void onOptionsClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		individualsNumV = Convert::ToInt32(algoOptions->individNum->Value);

		mutationNumV1 = Convert::ToInt32(algoOptions->mutationNum1->Value);
		mutationNumV2 = Convert::ToInt32(algoOptions->mutationNum2->Value);
		mutationNumV3 = Convert::ToInt32(algoOptions->mutationNum3->Value);
		mutationNumV4 = Convert::ToInt32(algoOptions->mutationNum4->Value);

		mutationProbV = Convert::ToInt32(algoOptions->mutationProb->Value);

		breedingNumV1 = Convert::ToInt32(algoOptions->breedingNum1->Value);
		breedingNumV2 = Convert::ToInt32(algoOptions->breedingNum2->Value);
		breedingNumV3 = Convert::ToInt32(algoOptions->breedingNum3->Value);

		algoOptions = gcnew AlgoOptions;
		algoOptions->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::onOptionsClosed);
		algoOptions->Visible = false;

		algoOptions->individNum->Value = Convert::ToDecimal(individualsNumV);

		algoOptions->mutationNum1->Value = Convert::ToDecimal(mutationNumV1);
		algoOptions->mutationNum2->Value = Convert::ToDecimal(mutationNumV2);
		algoOptions->mutationNum3->Value = Convert::ToDecimal(mutationNumV3);
		algoOptions->mutationNum4->Value = Convert::ToDecimal(mutationNumV4);

		algoOptions->mutationProb->Value = Convert::ToDecimal(mutationProbV);

		algoOptions->breedingNum1->Value = Convert::ToDecimal(breedingNumV1);
		algoOptions->breedingNum2->Value = Convert::ToDecimal(breedingNumV2);
		algoOptions->breedingNum3->Value = Convert::ToDecimal(breedingNumV3);
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		mutationList = new vector < EvolutionIt >();

		algoOptions = gcnew AlgoOptions;
		algoOptions->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::onOptionsClosed);
		algoOptions->Visible = false;

		algoOptions->individNum->Value = Convert::ToDecimal(individualsNumV);

		algoOptions->mutationNum1->Value = Convert::ToDecimal(mutationNumV1);
		algoOptions->mutationNum2->Value = Convert::ToDecimal(mutationNumV2);
		algoOptions->mutationNum3->Value = Convert::ToDecimal(mutationNumV3);
		algoOptions->mutationNum4->Value = Convert::ToDecimal(mutationNumV4);

		algoOptions->mutationProb->Value = Convert::ToDecimal(mutationProbV);

		algoOptions->breedingNum1->Value = Convert::ToDecimal(breedingNumV1);
		algoOptions->breedingNum2->Value = Convert::ToDecimal(breedingNumV2);
		algoOptions->breedingNum3->Value = Convert::ToDecimal(breedingNumV3);

		timerOn = false;

		this->Width = 938;
		this->Height = 640;

		problem = new GeneticSalesman();

		Graphics ^ g = clearWithBorder(bigGraphField);
		drawNodes(g, bigGraphField->Width);

		clearWithBorder(smallGraphField1);
		clearWithBorder(smallGraphField2);
	}

	private: System::Void btn_openFile_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ sfd = gcnew OpenFileDialog();
		sfd->Filter = "Text Files|*.txt|All Files|*.*";
		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			problem = new GeneticSalesman();

			using namespace Runtime::InteropServices;

			problem->loadFromFile((char*)(void*)Marshal::StringToHGlobalAnsi(sfd->FileName));

			Graphics ^ g = clearWithBorder(bigGraphField);
			drawNodes(g, bigGraphField->Width);
		}
	}
	private: System::Void btn_saveFile_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		sfd->Filter = "Text Files|*.txt|All Files|*.*";
		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			using namespace Runtime::InteropServices;

			problem->saveToFile((char*)(void*)Marshal::StringToHGlobalAnsi(sfd->FileName));
		}
	}

	private: System::Void mutationListBox_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		EvolutionIt getIteration = (*mutationList)[mutationListBox->SelectedIndex];

		Graphics ^ g = clearWithBorder(bigGraphField);
		drawEdges(g, getIteration.child, set < pair < int, int > >(), bigGraphField->Width, 0);
		drawNodes(g, bigGraphField->Width);

		Graphics ^ g2 = clearWithBorder(smallGraphField1);
		drawEdges(g2, getIteration.par1, getIteration.diff1, smallGraphField1->Width, 1);
		drawNodes(g2, smallGraphField1->Width);

		Graphics ^ g3 = clearWithBorder(smallGraphField2);
		drawEdges(g3, getIteration.par2, getIteration.diff2, smallGraphField2->Width, 1);
		drawNodes(g3, smallGraphField2->Width);
	}

	private: System::Void btn_algo_opts_Click(System::Object^  sender, System::EventArgs^  e) {
		algoOptions->Visible = !algoOptions->Visible;
	}

	private: System::Void btn_returnToMain_Click(System::Object^  sender, System::EventArgs^  e) {
		algoOptions->Close();
		this->Close();
	}
};
}