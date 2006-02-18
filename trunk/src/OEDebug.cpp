/*
 * Name		:	IOEDebug.cpp
 * Comment	:	Requires a lot to be done, it should form the
 * 			base of all debugging features in the software
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

/* minimum level of messages to be printed */
static OE_DLEVEL minDLevel = DL_ALL;

void oe_dbg_msg_handler (const wxString& msg, OE_DLEVEL level)
{
	if (level >= minDLevel)
		wxLogMessage (msg);
}

