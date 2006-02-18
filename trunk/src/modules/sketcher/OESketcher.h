/*
 * Name		:	OESketcher.h
 * Comment	:	Declares OESketcher class
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
#ifndef __OE_SKETCHER_HEADER__
#define __OE_SKETCHER_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <wx/splitter.h>
#include <wx/foldbar/foldpanelbar.h>
#include <wx/foldbar/foldpanelitem.h>

/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include <OEMain.h>
#include <IOEModule.h>
#include <components/OEGK/OEGKContext.h>
#include <components/OEGK/OEGKView.h>
#include <components/OEGK/OEGKCanvas.h>

/////////////////////////////////////////////////////////////////////
// OESketcher class declarations begins

class OESketcher : public IOEModule, wxEvtHandler
{
public:	/* fields */
	static const int FOEM_SKETCHER_NOCANVAS = 1 << 10;
	
	typedef enum {
		SKT_TOOL_SELECT = 0,
		SKT_TOOL_TWO_POINT_LINE,
		SKT_TOOL_GEOMETRIC_LINE,
		SKT_TOOL_RECTANGLE,
		SKT_TOOL_PARALLELOGRAM,
		SKT_TOOL_ELLIPSE,
		SKT_TOOL_ARC,
		SKT_TOOL_POINT,
		SKT_TOOL_SPLINE
	} SktTool;

	SktTool cur_tool;
	
public: /* methods */
			
	OESketcher ();
	~OESketcher ();

	/* Methods inherited from IOEModule */
	virtual void Init (OEBasicFrame* frame, const char* fname, const int flags);
	virtual void Main ();
	virtual void Destroy ();
	
	virtual OEBasicFrame* 	GetModuleFrame ();
	virtual void			SetModuleFrame (OEBasicFrame*);

	virtual const char*	GetFileName ();
	virtual void 		SetFileName (const char* fname);
	
	/* Methods specific to sketcher module */
	OEGKCanvas* 	GetOEGKCanvas ();
	void			SetOEGKCanvas (OEGKCanvas*);

	wxFoldPanelBar*	GetToolsPanel ();
	void			SetToolsPanel (wxFoldPanelBar* fpb);

protected:

	/* Event Handlers */
	void OnLineButtonClicked (wxCommandEvent&);
	void OnRectButtonClicked (wxCommandEvent&);
	void OnEllipseButtonClicked (wxCommandEvent&);
	void OnAdvancedButtonClicked (wxCommandEvent&);

	void OnToolSelected (wxCommandEvent&);
	
private:

	OEBasicFrame*		frame;
	OEGKCanvas* 		canvas;
	OEGKContext*		context;

	/* TODO: Replace this with a list of views
	 * Each view will have a name, and a corresponding
	 * page in view_tabs notebook */
	OEGKView*			view;
	wxFoldPanelBar*		tools_panel;
	wxFoldPanel			line_tools, rect_tools, 
						ellipse_tools, advanced_tools;
	wxSplitterWindow*	split_win;
	wxNotebook*			view_tabs;
	const char* 		fname;	
	const char*			module_name;// initialized in the constructor

	void CreateMenuBar (wxMenuBar*);


	enum {
		OESKT_FILE_SAVE = 15001,
		OESKT_FILE_REVERT,
		OESKT_FILE_CLOSE,
		OESKT_EDIT_UNDO,
		OESKT_EDIT_REDO,
		OESKT_EDIT_CLEAR,

		OESKT_TOOLS_SELECT_BUTTON,
		OESKT_TOOLS_LINE_BUTTON,
		OESKT_TOOLS_RECT_BUTTON,
		OESKT_TOOLS_ELLIPSE_BUTTON,
		OESKT_TOOLS_ADVANCED_BUTTON,

		OESKT_TOOLS_TWO_POINT_LINE,
		OESKT_TOOLS_GEOMETRIC_LINE,
		OESKT_TOOLS_RECTANGLE,
		OESKT_TOOLS_PARALLELOGRAM,
		OESKT_TOOLS_ELLIPSE,
		OESKT_TOOLS_ARC,
		OESKT_TOOLS_POINT,
		OESKT_TOOLS_SPLINE
	};

};

// OESketcher class declaration ends
/////////////////////////////////////////////////////////////////////

#endif /* __OE_SKETCHER_HEADER__ */
