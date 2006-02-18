/*
 *	FILE	:	OEGKCanvas.cpp
 *	AUTHOR	:	Hariprasad Govardhanam
 *	DESC	:
 *	LICENSE	:	(c) Hariprasad Govardhanam
 */

/////////////////////////////////////////////////////////////////////
// Standard include files

#include <errno.h>

/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OEGKCanvas.h"

/////////////////////////////////////////////////////////////////////
// OEGKCanvas member functions implementation begins

OEGKCanvas :: OEGKCanvas (wxWindow* parent, OEGKContext* c, OEGKView* v)
	: wxGLCanvas(parent,-1), x(0), y(0),
	mouse_button_click_handler(NULL), key_press_handler(NULL)
{
	is_init = false;
	
	OEGKContext* ctx = c;
	if (c == NULL)
		ctx = new OEGKContext ();
	RegisterContext (ctx);
	
	OEGKView* view = v;
	if (v == NULL)
		view = new OEGKView ();
	SetView (view);
}

OEGKCanvas :: ~OEGKCanvas ()
{
}

int
OEGKCanvas :: RegisterContext (OEGKContext* ctx)
{
	assert (ctx != NULL);
	
	vector<OEGKContext*>::iterator it;
	for (it = contexts.begin(); it != contexts.end(); it++)
	{
		if (*it == ctx)
			return EEXIST;
	}

	contexts.push_back (ctx);
	return 0;
}

/* TODO : Implement this function */
int
OEGKCanvas :: UnRegisterContext (OEGKContext* ctx)
{
	assert (ctx != NULL);
	
	vector<OEGKContext*>::iterator it;
	for (it = contexts.begin(); it != contexts.end(); it++)
	{
		if (*it == ctx)
		{
			//contexts.delete (ctx);
			return -1;
		}
	}
	
	return EINVAL;
}

int
OEGKCanvas :: SetActiveContext (OEGKContext* ctx)
{
	assert (ctx != NULL);
	
	vector<OEGKContext*>::iterator it;
	for (it = contexts.begin(); it != contexts.end(); it++)
	{
		if (*it == ctx)
		{
			active_context = ctx;
			return 0;
		}
	}
	
	return EINVAL;
}

void
OEGKCanvas :: SetView (OEGKView* v)
{
	assert (v != NULL);
	view = v;
}

void
OEGKCanvas :: Init ()
{
	int w,h;
	
	glShadeModel (GL_SMOOTH);

	GetClientSize(&w,&h);
	SetCurrent();
	glViewport(0, 0, (GLint) w, (GLint) h);

	/* clear color and depth buffers */
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);	
}

void
OEGKCanvas :: Render ()
{
	int w,h;
	wxPaintDC dc(this);	
	if (!GetContext()) return;
	
	SetCurrent();
	if(!is_init)
	{
		Init();
		is_init=TRUE;
	}	
		
	GetClientSize (&w,&h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (0.0, (1000.0*w)/h, 0.0, 1000.0f);
	
	/* clear color and depth buffers */
	glClear(GL_COLOR_BUFFER_BIT);	

	for (unsigned int i = 0; i < contexts.size() ; i++ )
	{
		for (unsigned int j = 0; j < contexts[i]->shapes.size() ; j++)
		{
			contexts[i]->shapes[j]->Draw();
		}
	}
	
	glFlush();
	SwapBuffers();
}

void
OEGKCanvas :: OnPaint (wxPaintEvent& pe)
{
	Render();
}

void
OEGKCanvas :: OnSize (wxSizeEvent& event)
{
	int w, h;
	wxGLCanvas::OnSize(event);

	GetClientSize(&w, &h);
	if (GetContext())
	{
		SetCurrent();
		glViewport(0, 0, (GLint) w, (GLint) h);
	}
}

void
OEGKCanvas :: OnEraseBackground (wxEraseEvent& evt)
{
}

void
OEGKCanvas :: OnMouseEvent (wxMouseEvent& evt)
{
	x = evt.m_x;
	y = evt.m_y;
	int w,h;
	
	if(evt.Entering())
	{
	}
	else if(evt.Leaving())
	{
		prevMouseX=0;
		prevMouseY=0;
		return;
	}
	else if(evt.LeftIsDown())
	{
		if (mouse_button_click_handler != NULL)
			mouse_button_click_handler (evt);
	}
	prevMouseX = x;
	prevMouseY = y;
}

BEGIN_EVENT_TABLE (OEGKCanvas, wxGLCanvas)
	EVT_PAINT(OEGKCanvas::OnPaint)
	EVT_SIZE(OEGKCanvas::OnSize)
	EVT_ERASE_BACKGROUND(OEGKCanvas::OnEraseBackground)
	EVT_MOUSE_EVENTS(OEGKCanvas::OnMouseEvent)
END_EVENT_TABLE ()

// OEGKCanvas member functions implementation ends
/////////////////////////////////////////////////////////////////////

