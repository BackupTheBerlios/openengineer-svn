/*
 *
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
