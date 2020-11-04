#pragma once

// Magnum Includes.
#include <Magnum/Platform/GLContext.h>

// wxWidgets Includes.
#include <wx/frame.h>
#include <wx/glcanvas.h>

class MainFrame : public wxFrame
{
public:
	explicit MainFrame( int argc, char** argv );
	~MainFrame();

private:
	void OnPaint( wxPaintEvent& event );

	wxGLCanvas* wxGlCanvas;
	wxGLContext* wxGlContext;
	Magnum::Platform::GLContext glContext;
};