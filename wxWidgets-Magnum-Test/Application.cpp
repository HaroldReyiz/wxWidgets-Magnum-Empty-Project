// Project Includes.
#include "Application.h"
#include "MainFrame.h"

wxIMPLEMENT_APP( Application );

bool Application::OnInit()
{
	MainFrame* frame = new MainFrame{ argc, argv };
	frame->Show( true );
	return true;
}