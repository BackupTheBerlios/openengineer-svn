/*
 * Name		:	IOEGKShape.h
 * Comment	:	Declares an interface IOEGKShape, that every
 * 			shape to be rendered by OEGKCanvas is to implement
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OEGK_SHAPE_HEADER__
#define __OEGK_SHAPE_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files
#include <GL/gl.h>
#include <GL/glu.h>

/////////////////////////////////////////////////////////////////////
// User-Defined include files
#include <OEMain.h>

/////////////////////////////////////////////////////////////////////
// IOEGKShape interface declaration begins

class IOEGKShape
{
	public:
		virtual void Draw () = 0;
		/* TODO: This should accept a rectangle */
		virtual bool IsInside () = 0;
};

// IOEGKShape interface declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OEGK_SHAPE_HEADER__ */

