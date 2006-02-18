/*
 * Name		:	OEApp.h
 * Comment	:	Declares OEApp class
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OE_APP_HEADER__
#define __OE_APP_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files
#include <wx/dynlib.h>

/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include "IOEModule.h"
#include "OEBasicFrame.h"

/////////////////////////////////////////////////////////////////////
// OEApp class declaration begins here

class OEApp : public wxApp
{
public:
	virtual bool OnInit ();

	/* Following functions serve like a 
	 * systemcalls for a kernel */
	IOEModule*  	LoadModule (const char* module_name, int flags);
	void		UnLoadModule (IOEModule*);

	void 		RegisterFrame (OEBasicFrame*);
	void 		UnRegisterFrame (OEBasicFrame*);
	
protected:
	void	 			RegisterModule (IOEModule*, wxDynamicLibrary*);
	wxDynamicLibrary*	UnRegisterModule (IOEModule*);

private:
	vector<OEBasicFrame*> frames;
	vector<IOEModule*> modules;

	//map<HOEModule> modules;
	//map<> frames;
};

DECLARE_APP(OEApp)

// OEApp class declaration ends here
/////////////////////////////////////////////////////////////////////

#endif /* __OE_APP_HEADER__ */
