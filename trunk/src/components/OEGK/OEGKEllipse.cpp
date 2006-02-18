/*
 *
 */

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include "OEGKEllipse.h"

/////////////////////////////////////////////////////////////////////
// OEGKEllipse class member functions implementation begins

OEGKEllipse :: OEGKEllipse ()
{
	center = NULL;
	xradius = 0;
	yradius = 0;
}

OEGKEllipse :: OEGKEllipse (OEGKPoint* c, OEREAL xrad, OEREAL yrad)
{
	center = c;
	xradius = xrad;
	yradius = yrad;
}

void
OEGKEllipse :: Draw ()
{
}

bool
OEGKEllipse :: IsInside ()
{
	return false;
}

OEGKPoint*
OEGKEllipse :: GetCenter ()
{
	return center;
}

void
OEGKEllipse :: SetCenter (OEGKPoint*c)
{
	center = c;
}

OEREAL
OEGKEllipse :: GetXRadius ()
{
	return xradius;
}

void
OEGKEllipse :: SetXRadius (OEREAL xrad)
{
	xradius = xrad;
}

OEREAL
OEGKEllipse :: GetYRadius ()
{
	return yradius;
}

void
OEGKEllipse :: SetYRadius (OEREAL yrad)
{
	yradius = yrad;
}


// OEGKEllipse class member functions implementation ends
/////////////////////////////////////////////////////////////////////

