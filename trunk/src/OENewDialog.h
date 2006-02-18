/*
 * Name		:	OENewDialog.h
 * Comment	:	Declares OENewDialog class
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OE_NEW_DIALOG_HEADER__
#define __OE_NEW_DIALOG_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"

/////////////////////////////////////////////////////////////////////
// OENewDialog class declaration begins

class OENewDialog : public wxDialog
{
public:
	OENewDialog ();
	~OENewDialog ();
	
	const char* GetSelectedModuleName ();

protected:
	DECLARE_EVENT_TABLE()
};

// OENewDialog class declaration ends
////////////////////////////////////////////////////////////////////

#endif /* __OE_NEW_DIALOG_HEADER__  */
