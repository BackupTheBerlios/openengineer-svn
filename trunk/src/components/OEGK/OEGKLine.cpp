/*
 *
 */

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEGKLine.h"

/////////////////////////////////////////////////////////////////////
// OEGKLine class member functions implementation begins

OEGKLine :: OEGKLine ()
{
	start = NULL;
	end = NULL;
}

OEGKLine :: OEGKLine (OEGKPoint* sp, OEGKPoint* ep)
{
	start = sp;
	end = ep;
}

void
OEGKLine :: Draw ()
{
	glBegin (GL_LINES);
		glColor3f (1.0f, 1.0f, 1.0f);
		glVertex3f (start->GetX(), start->GetY(), start->GetZ());
		glVertex3f (end->GetX(), end->GetY(), end->GetZ());
	glEnd ();
}

bool
OEGKLine :: IsInside ()
{
	return false;
}

OEGKPoint*
OEGKLine :: GetStartPoint ()
{
	return start;
}

void
OEGKLine :: SetStartPoint (OEGKPoint* sp)
{
	start = sp;
}

OEGKPoint*
OEGKLine :: GetEndPoint ()
{
	return end;
}

void
OEGKLine :: SetEndPoint  (OEGKPoint* ep)
{
	end = ep;
}

// OEGKLine class member functions implementation ends
/////////////////////////////////////////////////////////////////////

