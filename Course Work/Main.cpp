#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<System::String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CourseWork::MenuForm form;
	Application::Run(%form);
}