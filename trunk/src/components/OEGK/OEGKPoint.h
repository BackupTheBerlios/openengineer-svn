/*
 * Name		:	OEGKPoint.h
 * Comment	:	Declares OEGKPoint class, which implements
 * 			IOEGKShape interface
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OEGK_POINT_HEADER__
#define __OEGK_POINT_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files

/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include "IOEGKShape.h"

/////////////////////////////////////////////////////////////////////
// OEGKPoint class declaration begins

class OEGKPoint : public IOEGKShape
{
	public:
		OEGKPoint ();
		OEGKPoint (OEREAL x, OEREAL y, OEREAL z = 0);

		virtual void Draw ();
		virtual bool IsInside ();

		OEREAL 	GetX ();
		void	SetX (OEREAL);
		OEREAL 	GetY ();
		void	SetY (OEREAL);
		OEREAL 	GetZ ();
		void	SetZ (OEREAL);

	protected:
		OEREAL x, y, z;
};

// OEGKPoint class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OEGK_POINT_HEADER__ */

