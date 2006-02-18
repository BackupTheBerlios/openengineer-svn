/*
 * Name		:	OEBasicModuleLoader.h
 * Comment	:	Declares OEBasicModuleLoader class that implements
 * 			IOEModuleLoader interface
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OE_BASIC_MODULELOADER_HEADER__
#define __OE_BASIC_MODULELOADER_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files

#include <vector>

/////////////////////////////////////////////////////////////////////
// User-Defined include files


/////////////////////////////////////////////////////////////////////
// OEBasicModuleLoader class declaration begins

class OEBasicModuleLoader : public IOEModuleLoader
{
public:
	OEBasicModuleLoader ();
	~OEBasicModuleLoader ();
};

// OEBasicModuleLoader class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OE_BASIC_MODULELOADER_HEADER */
