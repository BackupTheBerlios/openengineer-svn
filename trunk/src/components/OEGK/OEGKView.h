/*
 * Name		:	OEGKView.h
 * Comment	:	Declares OEGKView class, which forms the third
 * 			component of the OEGK. This division of view from
 * 			canvas is necessary to make it easy for module
 * 			developers to support multiple views
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */

#ifndef __OEGK_VIEW_HEADER__
#define __OEGK_VIEW_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files


/////////////////////////////////////////////////////////////////////
// OEGKView class declaration begins

class OEGKView
{
	public:
		float view_matrix[4][4];

		OEGKView () { };
};

// OEGKView class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OEGK_VIEW_HEADER__  */
