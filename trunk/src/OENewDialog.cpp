/*
 * Name		:	OENewDialog.cpp
 * Comment	:	OENewDialog class is shown when the user wants
 * 			to open a new module document. This class will
 *			show the list of modules available and return
 *			the selected module
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"
#include "modules/sketcher/OESketcher.h"

/////////////////////////////////////////////////////////////////////
// OENewDialog member functions implementation begins

OENewDialog :: OENewDialog ()
{
/*	OESketcher *skt = new OESketcher ();
	skt->Init (NULL, NULL, 0);
	OEBasicFrame *frm = skt->GetModuleFrame ();
	
	assert (frm != NULL);
	
	frm->Show ();*/
}

OENewDialog :: ~OENewDialog ()
{
}

const char* 
OENewDialog :: GetSelectedModuleName ()
{
	return "sketcher";
}

BEGIN_EVENT_TABLE(OENewDialog,wxDialog)
END_EVENT_TABLE()

// OENewDialog member functions implementation ends
/////////////////////////////////////////////////////////////////////

