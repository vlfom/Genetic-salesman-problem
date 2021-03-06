﻿//
// AlgoOptionsForm.h
//

#pragma once

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AlgoOptions : public System::Windows::Forms::Form
	{
	public:
		AlgoOptions(void)
		{
			InitializeComponent();
		}

	protected:
		~AlgoOptions()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::GroupBox^  startOptionsGroup;
	private: System::Windows::Forms::GroupBox^  dynamicOptionsGroup;
	private: System::Windows::Forms::GroupBox^  breedingGroup;
	private: System::Windows::Forms::GroupBox^  mutationGroup;

	private: System::Windows::Forms::Label^  individNumDesc;
	private: System::Windows::Forms::Label^  mutationProbDesc;
	private: System::Windows::Forms::Label^  breedingNum1Desc;
	private: System::Windows::Forms::Label^  breedingNum2Desc;
	private: System::Windows::Forms::Label^  breedingNum3Desc;

	private: System::Windows::Forms::Label^  mutationNum1Desc;
	private: System::Windows::Forms::Label^  mutationNum2Desc;
	private: System::Windows::Forms::Label^  mutationNum3Desc;
	private: System::Windows::Forms::Label^  mutationNum4Desc;

	public: System::Windows::Forms::NumericUpDown^  individNum;
	public: System::Windows::Forms::NumericUpDown^  mutationProb;
	public: System::Windows::Forms::NumericUpDown^  breedingNum1;
	public: System::Windows::Forms::NumericUpDown^  breedingNum2;
	public: System::Windows::Forms::NumericUpDown^  breedingNum3;

	public: System::Windows::Forms::NumericUpDown^  mutationNum1;
	public: System::Windows::Forms::NumericUpDown^  mutationNum2;
	public: System::Windows::Forms::NumericUpDown^  mutationNum3;
	public: System::Windows::Forms::NumericUpDown^  mutationNum4;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->startOptionsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->individNumDesc = (gcnew System::Windows::Forms::Label());
			this->individNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->mutationProbDesc = (gcnew System::Windows::Forms::Label());
			this->mutationProb = (gcnew System::Windows::Forms::NumericUpDown());
			this->breedingGroup = (gcnew System::Windows::Forms::GroupBox());
			this->breedingNum3Desc = (gcnew System::Windows::Forms::Label());
			this->breedingNum2Desc = (gcnew System::Windows::Forms::Label());
			this->breedingNum1Desc = (gcnew System::Windows::Forms::Label());
			this->breedingNum3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->breedingNum2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->breedingNum1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->mutationGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mutationNum4Desc = (gcnew System::Windows::Forms::Label());
			this->mutationNum3Desc = (gcnew System::Windows::Forms::Label());
			this->mutationNum2Desc = (gcnew System::Windows::Forms::Label());
			this->mutationNum1Desc = (gcnew System::Windows::Forms::Label());
			this->mutationNum4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->mutationNum3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->mutationNum2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->mutationNum1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->dynamicOptionsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->startOptionsGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->individNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationProb))->BeginInit();
			this->breedingGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->breedingNum3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->breedingNum2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->breedingNum1))->BeginInit();
			this->mutationGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum1))->BeginInit();
			this->dynamicOptionsGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// startOptionsGroup
			// 
			this->startOptionsGroup->Controls->Add(this->individNumDesc);
			this->startOptionsGroup->Controls->Add(this->individNum);
			this->startOptionsGroup->Location = System::Drawing::Point(8, 8);
			this->startOptionsGroup->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->startOptionsGroup->Name = L"startOptionsGroup";
			this->startOptionsGroup->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->startOptionsGroup->Size = System::Drawing::Size(182, 73);
			this->startOptionsGroup->TabIndex = 29;
			this->startOptionsGroup->TabStop = false;
			this->startOptionsGroup->Text = L"Start conditions";
			// 
			// individNumDesc
			// 
			this->individNumDesc->AutoSize = true;
			this->individNumDesc->Location = System::Drawing::Point(10, 23);
			this->individNumDesc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->individNumDesc->Name = L"individNumDesc";
			this->individNumDesc->Size = System::Drawing::Size(131, 13);
			this->individNumDesc->TabIndex = 16;
			this->individNumDesc->Text = L"Number of representatives";
			// 
			// individNum
			// 
			this->individNum->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->individNum->Location = System::Drawing::Point(13, 38);
			this->individNum->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->individNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->individNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->individNum->Name = L"individNum";
			this->individNum->Size = System::Drawing::Size(159, 20);
			this->individNum->TabIndex = 16;
			this->individNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// mutationProbDesc
			// 
			this->mutationProbDesc->AutoSize = true;
			this->mutationProbDesc->Location = System::Drawing::Point(11, 23);
			this->mutationProbDesc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mutationProbDesc->Name = L"mutationProbDesc";
			this->mutationProbDesc->Size = System::Drawing::Size(115, 13);
			this->mutationProbDesc->TabIndex = 26;
			this->mutationProbDesc->Text = L"Mutation probability (%)";
			// 
			// mutationProb
			// 
			this->mutationProb->Location = System::Drawing::Point(13, 38);
			this->mutationProb->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mutationProb->Name = L"mutationProb";
			this->mutationProb->Size = System::Drawing::Size(159, 20);
			this->mutationProb->TabIndex = 25;
			this->mutationProb->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// breedingGroup
			// 
			this->breedingGroup->Controls->Add(this->breedingNum3Desc);
			this->breedingGroup->Controls->Add(this->breedingNum2Desc);
			this->breedingGroup->Controls->Add(this->breedingNum1Desc);
			this->breedingGroup->Controls->Add(this->breedingNum3);
			this->breedingGroup->Controls->Add(this->breedingNum2);
			this->breedingGroup->Controls->Add(this->breedingNum1);
			this->breedingGroup->Location = System::Drawing::Point(13, 66);
			this->breedingGroup->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->breedingGroup->Name = L"breedingGroup";
			this->breedingGroup->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->breedingGroup->Size = System::Drawing::Size(159, 98);
			this->breedingGroup->TabIndex = 17;
			this->breedingGroup->TabStop = false;
			this->breedingGroup->Text = L"Priority of crossover algorithms";
			// 
			// breedingNum3Desc
			// 
			this->breedingNum3Desc->AutoSize = true;
			this->breedingNum3Desc->Location = System::Drawing::Point(12, 76);
			this->breedingNum3Desc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->breedingNum3Desc->Name = L"breedingNum3Desc";
			this->breedingNum3Desc->Size = System::Drawing::Size(33, 13);
			this->breedingNum3Desc->TabIndex = 14;
			this->breedingNum3Desc->Text = L"No. 3";
			// 
			// breedingNum2Desc
			// 
			this->breedingNum2Desc->AutoSize = true;
			this->breedingNum2Desc->Location = System::Drawing::Point(12, 55);
			this->breedingNum2Desc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->breedingNum2Desc->Name = L"breedingNum2Desc";
			this->breedingNum2Desc->Size = System::Drawing::Size(33, 13);
			this->breedingNum2Desc->TabIndex = 13;
			this->breedingNum2Desc->Text = L"No. 2";
			// 
			// breedingNum1Desc
			// 
			this->breedingNum1Desc->AutoSize = true;
			this->breedingNum1Desc->Location = System::Drawing::Point(12, 34);
			this->breedingNum1Desc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->breedingNum1Desc->Name = L"breedingNum1Desc";
			this->breedingNum1Desc->Size = System::Drawing::Size(33, 13);
			this->breedingNum1Desc->TabIndex = 12;
			this->breedingNum1Desc->Text = L"No. 1";
			// 
			// breedingNum3
			// 
			this->breedingNum3->Location = System::Drawing::Point(49, 75);
			this->breedingNum3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->breedingNum3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->breedingNum3->Name = L"breedingNum3";
			this->breedingNum3->Size = System::Drawing::Size(96, 20);
			this->breedingNum3->TabIndex = 9;
			// 
			// breedingNum2
			// 
			this->breedingNum2->Location = System::Drawing::Point(49, 54);
			this->breedingNum2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->breedingNum2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->breedingNum2->Name = L"breedingNum2";
			this->breedingNum2->Size = System::Drawing::Size(96, 20);
			this->breedingNum2->TabIndex = 8;
			// 
			// breedingNum1
			// 
			this->breedingNum1->Location = System::Drawing::Point(49, 33);
			this->breedingNum1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->breedingNum1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->breedingNum1->Name = L"breedingNum1";
			this->breedingNum1->Size = System::Drawing::Size(96, 20);
			this->breedingNum1->TabIndex = 7;
			// 
			// mutationGroup
			// 
			this->mutationGroup->Controls->Add(this->mutationNum4Desc);
			this->mutationGroup->Controls->Add(this->mutationNum3Desc);
			this->mutationGroup->Controls->Add(this->mutationNum2Desc);
			this->mutationGroup->Controls->Add(this->mutationNum1Desc);
			this->mutationGroup->Controls->Add(this->mutationNum4);
			this->mutationGroup->Controls->Add(this->mutationNum3);
			this->mutationGroup->Controls->Add(this->mutationNum2);
			this->mutationGroup->Controls->Add(this->mutationNum1);
			this->mutationGroup->Location = System::Drawing::Point(188, 36);
			this->mutationGroup->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mutationGroup->Name = L"mutationGroup";
			this->mutationGroup->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mutationGroup->Size = System::Drawing::Size(159, 127);
			this->mutationGroup->TabIndex = 16;
			this->mutationGroup->TabStop = false;
			this->mutationGroup->Text = L"Priority of mutation algorithms";
			// 
			// mutationNum4Desc
			// 
			this->mutationNum4Desc->AutoSize = true;
			this->mutationNum4Desc->Location = System::Drawing::Point(12, 91);
			this->mutationNum4Desc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mutationNum4Desc->Name = L"mutationNum4Desc";
			this->mutationNum4Desc->Size = System::Drawing::Size(33, 13);
			this->mutationNum4Desc->TabIndex = 15;
			this->mutationNum4Desc->Text = L"No. 4";
			// 
			// mutationNum3Desc
			// 
			this->mutationNum3Desc->AutoSize = true;
			this->mutationNum3Desc->Location = System::Drawing::Point(12, 70);
			this->mutationNum3Desc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mutationNum3Desc->Name = L"mutationNum3Desc";
			this->mutationNum3Desc->Size = System::Drawing::Size(33, 13);
			this->mutationNum3Desc->TabIndex = 14;
			this->mutationNum3Desc->Text = L"No. 3";
			// 
			// mutationNum2Desc
			// 
			this->mutationNum2Desc->AutoSize = true;
			this->mutationNum2Desc->Location = System::Drawing::Point(12, 49);
			this->mutationNum2Desc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mutationNum2Desc->Name = L"mutationNum2Desc";
			this->mutationNum2Desc->Size = System::Drawing::Size(33, 13);
			this->mutationNum2Desc->TabIndex = 13;
			this->mutationNum2Desc->Text = L"No. 2";
			// 
			// mutationNum1Desc
			// 
			this->mutationNum1Desc->AutoSize = true;
			this->mutationNum1Desc->Location = System::Drawing::Point(12, 28);
			this->mutationNum1Desc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mutationNum1Desc->Name = L"mutationNum1Desc";
			this->mutationNum1Desc->Size = System::Drawing::Size(33, 13);
			this->mutationNum1Desc->TabIndex = 12;
			this->mutationNum1Desc->Text = L"No. 1";
			// 
			// mutationNum4
			// 
			this->mutationNum4->Location = System::Drawing::Point(49, 90);
			this->mutationNum4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mutationNum4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->mutationNum4->Name = L"mutationNum4";
			this->mutationNum4->Size = System::Drawing::Size(96, 20);
			this->mutationNum4->TabIndex = 10;
			// 
			// mutationNum3
			// 
			this->mutationNum3->Location = System::Drawing::Point(49, 69);
			this->mutationNum3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mutationNum3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->mutationNum3->Name = L"mutationNum3";
			this->mutationNum3->Size = System::Drawing::Size(96, 20);
			this->mutationNum3->TabIndex = 9;
			// 
			// mutationNum2
			// 
			this->mutationNum2->Location = System::Drawing::Point(49, 48);
			this->mutationNum2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mutationNum2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->mutationNum2->Name = L"mutationNum2";
			this->mutationNum2->Size = System::Drawing::Size(96, 20);
			this->mutationNum2->TabIndex = 8;
			// 
			// mutationNum1
			// 
			this->mutationNum1->Location = System::Drawing::Point(49, 27);
			this->mutationNum1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mutationNum1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->mutationNum1->Name = L"mutationNum1";
			this->mutationNum1->Size = System::Drawing::Size(96, 20);
			this->mutationNum1->TabIndex = 7;
			// 
			// dynamicOptionsGroup
			// 
			this->dynamicOptionsGroup->Controls->Add(this->mutationProbDesc);
			this->dynamicOptionsGroup->Controls->Add(this->mutationProb);
			this->dynamicOptionsGroup->Controls->Add(this->mutationGroup);
			this->dynamicOptionsGroup->Controls->Add(this->breedingGroup);
			this->dynamicOptionsGroup->Location = System::Drawing::Point(8, 84);
			this->dynamicOptionsGroup->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dynamicOptionsGroup->Name = L"dynamicOptionsGroup";
			this->dynamicOptionsGroup->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dynamicOptionsGroup->Size = System::Drawing::Size(356, 170);
			this->dynamicOptionsGroup->TabIndex = 30;
			this->dynamicOptionsGroup->TabStop = false;
			this->dynamicOptionsGroup->Text = L"Real-time parameters (can be changed during run)";
			// 
			// AlgoOptions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(372, 262);
			this->Controls->Add(this->dynamicOptionsGroup);
			this->Controls->Add(this->startOptionsGroup);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AlgoOptions";
			this->ShowIcon = false;
			this->Text = L"Algorithm parameters";
			this->startOptionsGroup->ResumeLayout(false);
			this->startOptionsGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->individNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationProb))->EndInit();
			this->breedingGroup->ResumeLayout(false);
			this->breedingGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->breedingNum3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->breedingNum2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->breedingNum1))->EndInit();
			this->mutationGroup->ResumeLayout(false);
			this->mutationGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mutationNum1))->EndInit();
			this->dynamicOptionsGroup->ResumeLayout(false);
			this->dynamicOptionsGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
