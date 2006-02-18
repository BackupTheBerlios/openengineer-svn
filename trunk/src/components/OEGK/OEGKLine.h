#ifndef __OEGK_LINE_HEADER__
#define __OEGK_LINE_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files

/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include "IOEGKShape.h"
#include "OEGKPoint.h"

/////////////////////////////////////////////////////////////////////
// OEGKLine class declaration begins

class OEGKLine : public IOEGKShape
{
	public:
		OEGKLine ();
		OEGKLine (OEGKPoint* start, OEGKPoint* end);

		virtual void Draw ();
		virtual bool IsInside ();

		OEGKPoint*	GetStartPoint ();
		void		SetStartPoint (OEGKPoint*);
		OEGKPoint* 	GetEndPoint ();
		void		SetEndPoint (OEGKPoint*);
	
	protected:
		OEGKPoint *start, *end;
};

// OEGKLine class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OEGK_LINE_HEADER__ */
