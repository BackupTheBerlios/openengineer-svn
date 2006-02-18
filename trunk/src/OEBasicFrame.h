/*
 * Name		:	OEBasicFrame.h
 * Comment	:	Declares OEBasicFrame class
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OE_BASIC_FRAME_HEADER__
#define __OE_BASIC_FRAME_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"
#include "OENewDialog.h"

/////////////////////////////////////////////////////////////////////
// OEBasicFrame class declaration begins

class OEBasicFrame : public wxFrame
{
public:
	OEBasicFrame (const wxString& title);
	~OEBasicFrame ();

protected:
	DECLARE_EVENT_TABLE ();

	enum {
		ID_FILE_NEW = 10001,
		ID_FILE_OPEN,
		ID_FILE_EXIT,

		ID_HELP_ABOUT
	};

	void 		CreateBasicMenuBar ();

	void 		OnFileNew (wxCommandEvent& evt);
	void 		OnFileExit (wxCommandEvent& evt);
	void 		OnFileOpen (wxCommandEvent& evt);
	void		OnHelpAbout (wxCommandEvent& evt);
};

// OEBasicFrame class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OE_BASIC_FRAME_HEADER__ */
