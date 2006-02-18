/*
 *	FILE	:	OENewDialog.cpp
 *	AUTHOR	:	Hariprasad Govardhanam
 *	DESC	:
 *	LICENSE	:	(c) Hariprasad Govardhanam
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

