/*
 * Name		:	OEGKEllipse.h
 * Comment	:	Declares a class OEGKEllipse, which implements
 * 			the interface IOEGKShape
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OEGK_ELLIPSE_HEADER__
#define __OEGK_ELLIPSE_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files

/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include "IOEGKShape.h"
#include "OEGKPoint.h"

/////////////////////////////////////////////////////////////////////
// OEGKEllipse class declaration begins
// TODO: Support for Rotated Ellipse

class OEGKEllipse : public IOEGKShape
{
	public:
		OEGKEllipse ();
		OEGKEllipse (OEGKPoint* center, OEREAL xradius, OEREAL yradius);

		virtual void Draw ();
		virtual bool IsInside ();

		OEGKPoint* 	GetCenter ();
		void		SetCenter (OEGKPoint*);
		OEREAL		GetXRadius ();
		void		SetXRadius (OEREAL);
		OEREAL		GetYRadius ();
		void		SetYRadius (OEREAL);

	protected:
		OEGKPoint*	center;
		OEREAL 		xradius, yradius;
};
// OEGKEllipse class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OEGK_ELLIPSE_HEADER__ */
