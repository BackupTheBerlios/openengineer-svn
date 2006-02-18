/*
 *	FILE	:	OEDebug.cpp
 *	AUTHOR	:	Hariprasad Govardhanam
 *	DESC	:
 *	LICENSE	:	(c) Hariprasad Govardhanam
 */

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"

/* minimum level of messages to be printed */
static OE_DLEVEL minDLevel = DL_ALL;

void oe_dbg_msg_handler (const wxString& msg, OE_DLEVEL level)
{
	if (level >= minDLevel)
		wxLogMessage (msg);
}

