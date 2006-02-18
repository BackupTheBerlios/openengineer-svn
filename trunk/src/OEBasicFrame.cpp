/*
 * Name		:	OEBasicFrame.cpp
 * Comment	:	Implements methods of class OEBasicFrame
 *			All the modules should use this class instead
 *			of their own class
 * License	:	(c)2006 Hariprasad Govardhanam
 *			Released under BSD-Style License
 *			Please LICENSE file accompanying this source
 * Changes	:	
 */

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"
#include "OEBasicFrame.h"

/////////////////////////////////////////////////////////////////////
// OEBasicFrame member functions implementation begin

OEBasicFrame :: OEBasicFrame (const wxString& title)
	: wxFrame (NULL, -1, title)
{
	CreateStatusBar ();
	CreateBasicMenuBar ();

	/* Register frame window, AFTER creating
	 * menubar */
	wxGetApp ().RegisterFrame (this);
}

OEBasicFrame :: ~OEBasicFrame ()
{
	wxGetApp ().UnRegisterFrame (this);
}

void OEBasicFrame :: CreateBasicMenuBar ()
{
	wxMenuBar* menuBar = new wxMenuBar ();

	wxMenu *fileMenu = new wxMenu ();
	wxMenu *helpMenu = new wxMenu ();

	fileMenu->Append (ID_FILE_NEW, "&New", "Create a new feature");
	fileMenu->Append (ID_FILE_OPEN, "&Open", "Open a feature");
	fileMenu->AppendSeparator ();
	fileMenu->Append (ID_FILE_EXIT, "E&xit", "Exit OpenEngineer");

	helpMenu->Append (ID_HELP_ABOUT, "About", "About this software");

	menuBar->Append (fileMenu, "&File");
	menuBar->Append (helpMenu, "&Help");

	SetMenuBar (menuBar);
}

BEGIN_EVENT_TABLE (OEBasicFrame, wxFrame)
	EVT_MENU (ID_FILE_NEW, OEBasicFrame::OnFileNew)
	EVT_MENU (ID_FILE_OPEN, OEBasicFrame::OnFileOpen)
	EVT_MENU (ID_FILE_EXIT, OEBasicFrame::OnFileExit)

	EVT_MENU (ID_HELP_ABOUT, OEBasicFrame::OnHelpAbout)
END_EVENT_TABLE ()


void
OEBasicFrame :: OnFileNew (wxCommandEvent& ce)
{
	OENewDialog *nd = new OENewDialog ();
	IOEModule* mod = wxGetApp().LoadModule (nd->GetSelectedModuleName (), 0);
}

void
OEBasicFrame :: OnFileExit (wxCommandEvent& ce)
{
	wxTheApp->ExitMainLoop ();
}

void
OEBasicFrame :: OnFileOpen (wxCommandEvent& ce)
{
}

void
OEBasicFrame :: OnHelpAbout (wxCommandEvent& ce)
{
}

// OEBasicFrame member functions implementation ends
/////////////////////////////////////////////////////////////////////

