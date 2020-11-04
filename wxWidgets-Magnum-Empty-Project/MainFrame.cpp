// Project Includes.
#include "MainFrame.h"

// Magnum Includes.
#include <Magnum/GL/DefaultFramebuffer.h>

// wxWidgets Includes.
#include <wx/frame.h>
#include <wx/glcanvas.h>
#include <wx/sizer.h>
#include <wx/version.h>

using namespace Magnum;

MainFrame::MainFrame( int argc, char** argv ) 
	: 
	wxFrame{ nullptr, wxID_ANY, "Magnum wxWidgets Application" }, 
	glContext{ NoCreate, argc, argv }
{
	wxBoxSizer* boxSizer;
	boxSizer = new wxBoxSizer{ wxVERTICAL };

#if (wxMAJOR_VERSION == 3) && (wxMINOR_VERSION >= 1)
	wxGLAttributes attributes;
	attributes.PlatformDefaults()
		.BufferSize( 24 )
		.MinRGBA( 8, 8, 8, 0 )
		.Depth( 24 )
		.Stencil( 0 )
		.DoubleBuffer()
		.EndList();
	wxGlCanvas = new wxGLCanvas{ this, attributes, wxID_ANY, wxDefaultPosition, wxSize{800, 600} };
#elif (wxMAJOR_VERSION == 3) && (wxMINOR_VERSION == 0)
	int attributes[] = { WX_GL_RGBA,
						 WX_GL_DOUBLEBUFFER,
						 WX_GL_DEPTH_SIZE, 24,
						 WX_GL_STENCIL_SIZE, 0,
						 0 };
	wxGlCanvas = new wxGLCanvas{ this, wxID_ANY, &attributes[ 0 ], wxDefaultPosition, wxSize{800, 600} };
#else
#error You need wxWidgets version 3.0 or later.
#endif

	wxGlContext = new wxGLContext{ wxGlCanvas };
	wxGlCanvas->SetCurrent( *wxGlContext );
	glContext.create();

	boxSizer->Add( wxGlCanvas, 1, wxALL | wxEXPAND, 5 );
	SetSizer( boxSizer );

	Layout();

	boxSizer->Fit( this );

	Centre( wxBOTH );

	wxGlCanvas->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), nullptr, this );

	/* TODO: Add your initialization code here */
}

MainFrame::~MainFrame()
{
	wxGlCanvas->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), nullptr, this );
}

void MainFrame::OnPaint( wxPaintEvent& event )
{
	GL::defaultFramebuffer.clear( GL::FramebufferClear::Color );

	/* TODO: Add your drawing code here */

	wxGlCanvas->SwapBuffers();
}