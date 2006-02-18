/*
 *	FILE	:	OEBasicModuleLoader.cpp
 *	AUTHOR	:	Hariprasad Govardhanam
 *	DESC	:
 *	LICENSE	:	(c) Hariprasad Govardhanam
 */

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"
#include "OEBasicModuleLoader.h"

/////////////////////////////////////////////////////////////////////
// OEBasicModuleLoader member functions implementation begins

IOEModule*
OEBasicModuleLoader :: LoadModule (
				const char* szModName, 
				OEBasicFrame* frame,
				const char* szFileName,
				int moduleFlags)
{
	
}

bool
OEBasicModuleLoader :: UnLoadModule (IOEModule* module)
{
}

// OEBasicModuleLoader member functions implementation ends
/////////////////////////////////////////////////////////////////////

