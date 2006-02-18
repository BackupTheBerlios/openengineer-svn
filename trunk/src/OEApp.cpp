/*
 *	FILE	:	OEApp.cpp
 *	AUTHOR	:	Hariprasad Govardhanam
 *	DESC	:	
 *	LICENSE	:	(c) Hariprasad Govardhanam
 */

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEMain.h"
#include "OEApp.h"
#include "modules/sketcher/OESketcher.h"

/////////////////////////////////////////////////////////////////////
// OEApp Member functions implementation begins

IMPLEMENT_APP(OEApp)

bool OEApp::OnInit ()
{	
	OEBasicFrame *mainFrame = new OEBasicFrame ("Open Engineer");
	mainFrame->Show (TRUE);
	SetTopWindow (static_cast<wxWindow*>(mainFrame));

	DBG_MSG ("OEApp::OnInit Leaving");
	return true;
}

IOEModule*
OEApp :: LoadModule (const char* module_name, int flags = 0)
{
/*	wxString can_mod_name = wxDynamicLibrary :: CanonicalizeName (module_name);
	wxDynamicLibrary *dlib = new wxDynamicLibrary (can_mod_name);
	typedef IOEModule* (*func_get_mod_type)(void);
   	func_get_mod_type getmod = (func_get_mod_type) dlib->GetSymbol ("GetModule");
	if (getmod == NULL)
		ERR_MSG ("ERROR:Unable to load module");

	IOEModule* mod = getmod ();
	RegisterModule (mod, dlib);
	return mod;*/
	IOEModule* mod = new OESketcher();
	mod->Init (dynamic_cast<OEBasicFrame*>(GetTopWindow()), NULL, 0);
	mod->GetModuleFrame ()->Show ();
	return mod;
}

void
OEApp :: UnLoadModule (IOEModule* mod)
{
	wxDynamicLibrary* dlib = UnRegisterModule (mod);
	mod->Destroy ();
	delete dlib;
}

void
OEApp :: RegisterFrame (OEBasicFrame* frame)
{
	std::vector<OEBasicFrame*>::iterator ip;
	for (ip = frames.begin (); ip != frames.end (); ip++) {
		if (*ip == frame) {
			return;
		}
	}
	frames.push_back (frame);
}

void
OEApp :: UnRegisterFrame (OEBasicFrame* frame)
{
	std::vector<OEBasicFrame*>::iterator pos = 
				find (frames.begin (), frames.end (), frame);
	if (pos != frames.end())
	{
		frames.erase (pos);
	}
}

void
OEApp :: RegisterModule (IOEModule* mod, wxDynamicLibrary *dlib)
{
	
}

wxDynamicLibrary*
OEApp :: UnRegisterModule (IOEModule* mod)
{
	return NULL;
}

// OEApp Member functions implementation ends
/////////////////////////////////////////////////////////////////////

