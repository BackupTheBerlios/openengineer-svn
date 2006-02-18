#ifndef __OE_IMODULE_HEADER__
#define __OE_IMODULE_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"
#include "OEBasicFrame.h"

/////////////////////////////////////////////////////////////////////
// IOEModule interface declaration begins

class IOEModule
{
public:
	static const int FOEM_NOINIT = 0x1;

	virtual void Init (OEBasicFrame* frame, const char* fname, const int flags) = 0;
	virtual void Main () = 0;
	virtual void Destroy () = 0;
	
	virtual OEBasicFrame* 	GetModuleFrame () = 0;
	virtual void 			SetModuleFrame (OEBasicFrame*) = 0;
	
	virtual const char* GetFileName () = 0;
	virtual void 		SetFileName (const char* fname) = 0;
};

// IOEModule interface declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OE_IMODULE_HEADER__ */
