//
// AlgoOptionsForm.h
//

#pragma once

#include "MainForm.h"

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_start;
	private: System::Windows::Forms::Button^  btn_about;
	private: System::Windows::Forms::Button^  btn_exit;

	private: System::Windows::Forms::Label^  label_desc1;
	private: System::Windows::Forms::Label^  label_desc2;
	private: System::Windows::Forms::Label^  label_desc3;
	private: System::Windows::Forms::Label^  label_sign1;
	private: System::Windows::Forms::Label^  label_sign2;



	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->btn_about = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->label_desc1 = (gcnew System::Windows::Forms::Label());
			this->label_desc2 = (gcnew System::Windows::Forms::Label());
			this->label_desc3 = (gcnew System::Windows::Forms::Label());
			this->label_sign1 = (gcnew System::Windows::Forms::Label());
			this->label_sign2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_start
			// 
			this->btn_start->BackColor = System::Drawing::SystemColors::Menu;
			this->btn_start->Location = System::Drawing::Point(76, 196);
			this->btn_start->Margin = System::Windows::Forms::Padding(2);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(233, 31);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"Start";
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &MenuForm::btn_start_Click);
			// 
			// btn_about
			// 
			this->btn_about->BackColor = System::Drawing::SystemColors::Menu;
			this->btn_about->Location = System::Drawing::Point(76, 230);
			this->btn_about->Margin = System::Windows::Forms::Padding(2);
			this->btn_about->Name = L"btn_about";
			this->btn_about->Size = System::Drawing::Size(233, 31);
			this->btn_about->TabIndex = 1;
			this->btn_about->Text = L"About";
			this->btn_about->UseVisualStyleBackColor = false;
			this->btn_about->Click += gcnew System::EventHandler(this, &MenuForm::btn_about_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->BackColor = System::Drawing::SystemColors::Menu;
			this->btn_exit->Location = System::Drawing::Point(76, 265);
			this->btn_exit->Margin = System::Windows::Forms::Padding(2);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(233, 31);
			this->btn_exit->TabIndex = 2;
			this->btn_exit->Text = L"Exit";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MenuForm::btn_exit_Click);
			// 
			// label_desc1
			// 
			this->label_desc1->AutoSize = true;
			this->label_desc1->BackColor = System::Drawing::Color::White;
			this->label_desc1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_desc1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_desc1->Location = System::Drawing::Point(152, 118);
			this->label_desc1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_desc1->Name = L"label_desc1";
			this->label_desc1->Padding = System::Windows::Forms::Padding(1);
			this->label_desc1->Size = System::Drawing::Size(79, 21);
			this->label_desc1->TabIndex = 3;
			this->label_desc1->Text = L"Solution to";
			// 
			// label_desc2
			// 
			this->label_desc2->AutoSize = true;
			this->label_desc2->BackColor = System::Drawing::Color::White;
			this->label_desc2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_desc2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_desc2->Location = System::Drawing::Point(64, 138);
			this->label_desc2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_desc2->Name = L"label_desc2";
			this->label_desc2->Padding = System::Windows::Forms::Padding(3);
			this->label_desc2->Size = System::Drawing::Size(260, 32);
			this->label_desc2->TabIndex = 4;
			this->label_desc2->Text = L"Traveling Salesman Problem";
			// 
			// label_desc3
			// 
			this->label_desc3->AutoSize = true;
			this->label_desc3->BackColor = System::Drawing::Color::White;
			this->label_desc3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_desc3->Location = System::Drawing::Point(104, 169);
			this->label_desc3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_desc3->Name = L"label_desc3";
			this->label_desc3->Padding = System::Windows::Forms::Padding(2, 3, 1, 3);
			this->label_desc3->Size = System::Drawing::Size(176, 21);
			this->label_desc3->TabIndex = 5;
			this->label_desc3->Text = L"using Genetic Algorithms approach";
			// 
			// label_sign1
			// 
			this->label_sign1->AutoSize = true;
			this->label_sign1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_sign1->Location = System::Drawing::Point(266, 9);
			this->label_sign1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_sign1->Name = L"label_sign1";
			this->label_sign1->Size = System::Drawing::Size(95, 15);
			this->label_sign1->TabIndex = 6;
			this->label_sign1->Text = L"Implemented by";
			// 
			// label_sign2
			// 
			this->label_sign2->AutoSize = true;
			this->label_sign2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_sign2->Location = System::Drawing::Point(247, 26);
			this->label_sign2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_sign2->Name = L"label_sign2";
			this->label_sign2->Size = System::Drawing::Size(117, 16);
			this->label_sign2->TabIndex = 7;
			this->label_sign2->Text = L"Vladimir Fomenko";
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(385, 354);
			this->Controls->Add(this->label_sign2);
			this->Controls->Add(this->label_sign1);
			this->Controls->Add(this->label_desc3);
			this->Controls->Add(this->label_desc2);
			this->Controls->Add(this->label_desc1);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_about);
			this->Controls->Add(this->btn_start);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MenuForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void onMainFormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		this->Visible = true;
	}

	private: System::Void btn_start_Click(System::Object^  sender, System::EventArgs^  e) {
		CourseWork::MyForm ^myForm = gcnew MyForm;
		myForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MenuForm::onMainFormClosed);
		this->Visible = false;
		myForm->Show(this);
	}

	private: System::Void btn_about_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show(L"Course work on \n\"Solving TSP (Traveling Salesman Problem)\nusing Genetic Algorithms method\"", "Notification", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
