/*
 * Name		:	OEGKContext.h
 * Comment	:	Declares OEGKContext class, which works like
 * 			a display list. The graphic primitives in this
 *			context are rendered into a OEGKCanvas, when it
 * 			is registered into OEGKCanvas
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OEGK_CONTEXT_HEADER__
#define __OEGK_CONTEXT_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files
#include <vector>

using namespace std;
/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include "IOEGKShape.h"

/////////////////////////////////////////////////////////////////////
// OEGKContext class declaration begins

class OEGKContext
{
	public:
		vector<IOEGKShape*> shapes;
};

// OEGKContext class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OEGK_CONTEXT_HEADER__ */
