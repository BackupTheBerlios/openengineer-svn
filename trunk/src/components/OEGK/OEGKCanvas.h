#ifndef __OEGK_CANVAS_HEADER__
#define __OEGK_CANVAS_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files

#include <wx/glcanvas.h>
#include <GL/gl.h>

/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "../../OEMain.h"
#include "OEGKContext.h"
#include "OEGKView.h"

/////////////////////////////////////////////////////////////////////
// OEGKCanvas class declaration begins

class OEGKCanvas : public wxGLCanvas
{
public:
	typedef void (*MouseButtonClickHandler)(wxMouseEvent& evt);
	typedef void (*KeyPressHandler)(wxKeyEvent& evt);
	
	long int x, y;
		
	OEGKCanvas (wxWindow*, OEGKContext* context = NULL, OEGKView* view = NULL);
	~OEGKCanvas ();

	MouseButtonClickHandler	GetMouseButtonClickHandler (void);
	void 					SetMouseButtonClickHandler (MouseButtonClickHandler);

	KeyPressHandler 		GetKeyPressHandler (void);
	void					SetKeyPressHandler (KeyPressHandler);
			
protected:
	DECLARE_EVENT_TABLE()

	vector<OEGKContext*> contexts;
	OEGKContext* active_context;
	OEGKView* view;
	
	bool is_init;
	int prevMouseX, prevMouseY;	

	MouseButtonClickHandler mouse_button_click_handler;
	KeyPressHandler key_press_handler;

	void Init ();
	void Render ();

	int RegisterContext (OEGKContext*);
	int UnRegisterContext (OEGKContext*);
	int SetActiveContext (OEGKContext*);

	void SetView (OEGKView*);
	
	void OnPaint (wxPaintEvent&);
	void OnSize (wxSizeEvent&);
	void OnEraseBackground (wxEraseEvent&);
	void OnMouseEvent (wxMouseEvent& evt);
};

// OEGKCanvas class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OEGK_CANVAS_HEADER__ */
