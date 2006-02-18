/*
 * Name		:	OEBasicModuleLoader.cpp
 * Comment	:	Implements the OEBasicModuleLoader class
 * 			methods
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

