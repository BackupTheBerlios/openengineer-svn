/*
 * Name		:	OEGKPoint.cpp
 * Comment	:	Implements methods in OEGKPoint class, which
 			implements IOEGKShape interface for a point
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include "OEGKPoint.h"

/////////////////////////////////////////////////////////////////////
// OEGKPoint class member functions implementation begins

OEGKPoint :: OEGKPoint ()
{
	x = y = z = 0;
}

OEGKPoint :: OEGKPoint (OEREAL xv, OEREAL yv, OEREAL zv)
{
	x = xv;
	y = yv;
	z = zv;
}

void
OEGKPoint :: Draw ()
{
}

bool
OEGKPoint :: IsInside ()
{
	return false;
}

OEREAL
OEGKPoint :: GetX ()
{
	return x;
}

void
OEGKPoint :: SetX (OEREAL xv)
{
	x = xv;
}

OEREAL
OEGKPoint :: GetY ()
{
	return y;
}

void
OEGKPoint :: SetY (OEREAL yv)
{
	y = yv;
}

OEREAL
OEGKPoint :: GetZ ()
{
	return z;
}

void
OEGKPoint :: SetZ (OEREAL zv)
{
	z = zv;
}

// OEGKPoint class member functions implementation ends
/////////////////////////////////////////////////////////////////////
