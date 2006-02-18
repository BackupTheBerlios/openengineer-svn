/*
 *	FILE	:	OESketcher.cpp
 *	AUTHOR	:	Hariprasad Govardhanam
 *	DESC	:
 *	LICENSE	:	(c)	Hariprasad Govardhanam
 */

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files

#include "OESketcher.h"
#include <components/OEGK/OEGKPoint.h>
#include <components/OEGK/OEGKLine.h>

/////////////////////////////////////////////////////////////////////
// OESketcher member functions implementation begins

OESketcher :: OESketcher ()
				:wxEvtHandler (),line_tools(NULL), 
				rect_tools(NULL), ellipse_tools(NULL),
				advanced_tools(NULL), cur_tool(SKT_TOOL_SELECT)
{
	module_name = "Sketcher";
	context = NULL;
	view = NULL;
	tools_panel = NULL;
}

OESketcher :: ~OESketcher ()
{
}

void
OESketcher :: Init (OEBasicFrame* frame, const char* fname, const int flags)
{
	SetModuleFrame (frame);
	SetFileName (fname);
}

void
OESketcher :: Main ()
{
}

void
OESketcher :: Destroy ()
{
}

OEBasicFrame* 
OESketcher :: GetModuleFrame ()
{
	return frame;
}

void
OESketcher :: SetModuleFrame (OEBasicFrame* f)
{
	if (f == NULL) {
		frame = new OEBasicFrame (module_name);
	} else {
		frame = f;
	}

	CreateMenuBar (frame->GetMenuBar ());
	split_win = new wxSplitterWindow (frame, wxID_ANY, wxDefaultPosition,
						wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE);
	wxSplitterWindow* vsplit_win = new wxSplitterWindow (split_win, wxID_ANY, 
					wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE);
	
	view_tabs = new wxNotebook (dynamic_cast<wxWindow*>(vsplit_win), wxID_ANY,
						wxDefaultPosition, wxDefaultSize, wxNB_BOTTOM);
	
	wxTextCtrl* msg_logger = new wxTextCtrl (vsplit_win, wxID_ANY, "", 
					wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	msg_logger->SetEditable (false);
	wxLogTextCtrl* mlog = new wxLogTextCtrl (msg_logger);
	
	SetOEGKCanvas (NULL);
	SetToolsPanel (NULL);
	
	view_tabs->AddPage (canvas, "Default");
	
	vsplit_win->SplitHorizontally (dynamic_cast<wxWindow*>(view_tabs), 
					dynamic_cast<wxWindow*>(msg_logger));
	split_win->SplitVertically (tools_panel, vsplit_win, 175);
}

const char*
OESketcher :: GetFileName ()
{
	return fname;
}

void
OESketcher :: SetFileName (const char* name)
{
	if (name == NULL) {
		/* TODO: Create a temporary name for the sketch 
		 * like untitled */
		fname = "Untitled";
	} else {
		fname = name;
	}
	
	wxString str;
	str.Printf ("%s - %s", fname, module_name);
	frame->SetTitle (str);
}

OEGKCanvas*
OESketcher :: GetOEGKCanvas ()
{
	return canvas;
}

/*TODO: An issue related to split_win and view_tabs
 * arises here */
void
OESketcher :: SetOEGKCanvas (OEGKCanvas* c)
{
	if (c == NULL) {
		context = new OEGKContext ();
		canvas = new OEGKCanvas (dynamic_cast<wxWindow*>(view_tabs), context, view);
		OEGKPoint* pt1 = new OEGKPoint (0.0,0.0);
		OEGKPoint* pt2 = new OEGKPoint (1000.0,0.0);
		OEGKLine* line = new OEGKLine (pt1, pt2);
		OEGKPoint* pty1 = new OEGKPoint (0.0, 1000.0);
		OEGKLine* line2 = new OEGKLine (pt1, pty1);
		context->shapes.push_back (line);
		context->shapes.push_back (line2);
	} else {
		c = canvas;
//		c->RegisterContext (context);
	}
}

wxFoldPanelBar*
OESketcher :: GetToolsPanel ()
{
	return tools_panel;
}

void
OESketcher :: SetToolsPanel (wxFoldPanelBar* fpb)
{
	if (fpb == NULL) {
		tools_panel = new wxFoldPanelBar (dynamic_cast<wxWindow*>(split_win));
	} else {
		tools_panel = fpb;
	}
	
	/* Create main tools panel and add buttons to it */
	wxFoldPanel main_tools = tools_panel->AddFoldPanel ("Tools");
		
	wxToggleButton* select_button, *line_button, *rect_button, 
			*ellipse_button, *advanced_button;
	
	select_button = new wxToggleButton (main_tools.GetParent(), OESKT_TOOLS_SELECT_BUTTON, 
					"Select", wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);
	line_button = new wxToggleButton (main_tools.GetParent(), OESKT_TOOLS_LINE_BUTTON, 
					"Line",	wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);
	rect_button = new wxToggleButton (main_tools.GetParent(), OESKT_TOOLS_RECT_BUTTON, 
					"Rectangle", wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);
	ellipse_button = new wxToggleButton (main_tools.GetParent(), OESKT_TOOLS_ELLIPSE_BUTTON, 
					"Ellipse", wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);
	advanced_button = new wxToggleButton (main_tools.GetParent(), OESKT_TOOLS_ADVANCED_BUTTON, 
					"Advanced",	wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);
	
	tools_panel->AddFoldPanelWindow (main_tools, select_button, wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (main_tools, line_button, wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (main_tools, rect_button, wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (main_tools, ellipse_button, wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (main_tools, advanced_button, wxFPB_ALIGN_WIDTH, 2, 4, 4);


	/* Now connect event handlers to different tools */

	select_button->Connect (OESKT_TOOLS_SELECT_BUTTON, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);
	line_button->Connect (OESKT_TOOLS_LINE_BUTTON, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnLineButtonClicked), NULL, this);
	rect_button->Connect (OESKT_TOOLS_RECT_BUTTON, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnRectButtonClicked), NULL, this);
	ellipse_button->Connect (OESKT_TOOLS_ELLIPSE_BUTTON, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnEllipseButtonClicked), NULL, this);
	advanced_button->Connect (OESKT_TOOLS_ADVANCED_BUTTON, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnAdvancedButtonClicked), NULL, this);

	
	/* Create line tools panel and add buttons to it */
	line_tools = tools_panel->AddFoldPanel ("Line Tools");

	wxButton* two_point_line_button, *geometric_line_button;
	
	two_point_line_button = new wxButton (line_tools.GetParent(), OESKT_TOOLS_TWO_POINT_LINE, 
					"Two Point Line", wxDefaultPosition, wxDefaultSize, 
					wxBU_EXACTFIT|wxNO_BORDER);
	geometric_line_button = new wxButton (line_tools.GetParent(), OESKT_TOOLS_GEOMETRIC_LINE, 
					"Geometric Line", wxDefaultPosition, wxDefaultSize, 
					wxBU_EXACTFIT|wxNO_BORDER);

	tools_panel->AddFoldPanelWindow (line_tools, two_point_line_button, 
					wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (line_tools, geometric_line_button, 
					wxFPB_ALIGN_WIDTH, 2, 4, 4);
	
	two_point_line_button->Connect (OESKT_TOOLS_TWO_POINT_LINE, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);
	geometric_line_button->Connect (OESKT_TOOLS_GEOMETRIC_LINE, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);

	/* Hide it */
	line_tools.GetParent()->Hide ();

	/* Create rect tools panel and add buttons to it */
	rect_tools = tools_panel->AddFoldPanel ("Rectangle Tools");

	wxButton* rectangle_button, *parallelogram_button;
	
	rectangle_button = new wxButton (rect_tools.GetParent(), OESKT_TOOLS_RECTANGLE, 
					"Rectangle", wxDefaultPosition, wxDefaultSize, 
					wxBU_EXACTFIT|wxNO_BORDER);
	parallelogram_button = new wxButton (rect_tools.GetParent(), OESKT_TOOLS_PARALLELOGRAM, 
					"Parallelogram", wxDefaultPosition, wxDefaultSize, 
					wxBU_EXACTFIT|wxNO_BORDER);

	tools_panel->AddFoldPanelWindow (rect_tools, rectangle_button, 
					wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (rect_tools, parallelogram_button, 
					wxFPB_ALIGN_WIDTH, 2, 4, 4);

	rectangle_button->Connect (OESKT_TOOLS_RECTANGLE, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);
	parallelogram_button->Connect (OESKT_TOOLS_PARALLELOGRAM, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);
	
	/* Hide it */
	rect_tools.GetParent()->Hide ();

	
	ellipse_tools = tools_panel->AddFoldPanel ("Ellipse Tools");

	wxButton* arc_button, *ellipse_tool_button;

	arc_button = new wxButton (ellipse_tools.GetParent(), OESKT_TOOLS_ARC, "Arc",
					wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);
	ellipse_tool_button = new wxButton (ellipse_tools.GetParent (), OESKT_TOOLS_ELLIPSE, 
					"Ellipse", wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);

	tools_panel->AddFoldPanelWindow (ellipse_tools, arc_button,
					wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (ellipse_tools, ellipse_tool_button,
					wxFPB_ALIGN_WIDTH, 2, 4, 4);

	arc_button->Connect (OESKT_TOOLS_ARC, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);
	ellipse_button->Connect (OESKT_TOOLS_ELLIPSE, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);

	/* Hide it */
	ellipse_tools.GetParent()->Hide ();

	advanced_tools = tools_panel->AddFoldPanel ("Advanced Tools");

	wxButton* point_button, *spline_button;

	point_button = new wxButton (advanced_tools.GetParent(), OESKT_TOOLS_POINT, "Point",
					wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);
	spline_button = new wxButton (advanced_tools.GetParent (), OESKT_TOOLS_SPLINE, "Spline",
					wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT|wxNO_BORDER);

	tools_panel->AddFoldPanelWindow (advanced_tools, point_button,
					wxFPB_ALIGN_WIDTH, 2, 4, 4);
	tools_panel->AddFoldPanelWindow (advanced_tools, spline_button,
					wxFPB_ALIGN_WIDTH, 2, 4, 4);

	point_button->Connect (OESKT_TOOLS_POINT, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);
	spline_button->Connect (OESKT_TOOLS_SPLINE, wxEVT_COMMAND_BUTTON_CLICKED,
					wxCommandEventHandler (OESketcher::OnToolSelected), NULL, this);
	/* Hide it */
	advanced_tools.GetParent()->Hide ();

	/* Style must be set at last, or it is taking
	 * default style */
	wxCaptionBarStyle cs;
	cs.SetCaptionStyle (wxCAPTIONBAR_FILLED_RECTANGLE);
	tools_panel->ApplyCaptionStyleAll (cs);
}

void
OESketcher :: CreateMenuBar (wxMenuBar* menubar)
{
	if (menubar == NULL) {
		menubar = new wxMenuBar ();
	}
	
	int file_index = menubar->FindMenu ("&File");
	if (file_index != -1)
	{
		wxMenu *file_menu = menubar->GetMenu (file_index);
		file_menu->Insert (2, OESKT_FILE_SAVE, "Save");
		file_menu->Insert (3, OESKT_FILE_REVERT, "Revert");
		file_menu->Insert (4, OESKT_FILE_CLOSE, "Close");

		wxMenu *edit_menu = new wxMenu ();
		edit_menu->Append (OESKT_EDIT_UNDO, "Undo");
		edit_menu->Append (OESKT_EDIT_REDO, "Redo");
		edit_menu->Append (OESKT_EDIT_CLEAR, "Clear");
		menubar->Insert (file_index+1, edit_menu, "&Edit");
	}
}

/* Event Handlers */

void
OESketcher :: OnLineButtonClicked (wxCommandEvent& ce)
{
	if (ce.IsChecked ())
		line_tools.GetParent ()->Show ();
	else
		line_tools.GetParent ()->Hide ();
}

void
OESketcher :: OnRectButtonClicked (wxCommandEvent& ce)
{
	if (ce.IsChecked ())
		rect_tools.GetParent ()->Show ();
	else
		rect_tools.GetParent ()->Hide ();
}

void
OESketcher :: OnEllipseButtonClicked (wxCommandEvent& ce)
{
	if (ce.IsChecked ())
		ellipse_tools.GetParent ()->Show ();
	else
		ellipse_tools.GetParent ()->Hide ();
}

void
OESketcher :: OnAdvancedButtonClicked (wxCommandEvent& ce)
{
	if (ce.IsChecked ())
		advanced_tools.GetParent ()->Show ();
	else
		advanced_tools.GetParent ()->Hide ();
}

void
OESketcher :: OnToolSelected (wxCommandEvent& ce)
{
	int id = ce.GetId ();
	
	if (id == OESKT_TOOLS_SELECT_BUTTON) {
		cur_tool = SKT_TOOL_SELECT;
	} else if (id == OESKT_TOOLS_TWO_POINT_LINE) {
		cur_tool = SKT_TOOL_TWO_POINT_LINE;
	} else if (id == OESKT_TOOLS_GEOMETRIC_LINE) {
		cur_tool = SKT_TOOL_GEOMETRIC_LINE;
	} else if (id == OESKT_TOOLS_RECTANGLE) {
		cur_tool = SKT_TOOL_RECTANGLE;
	} else if (id == OESKT_TOOLS_PARALLELOGRAM) {
		cur_tool = SKT_TOOL_PARALLELOGRAM;
	} else if (id == OESKT_TOOLS_ELLIPSE) {
		cur_tool = SKT_TOOL_ELLIPSE;
	} else if (id == OESKT_TOOLS_ARC) {
		cur_tool = SKT_TOOL_ARC;
	} else if (id == OESKT_TOOLS_POINT) {
		cur_tool = SKT_TOOL_POINT;
	} else if (id == OESKT_TOOLS_SPLINE) {
		cur_tool = SKT_TOOL_SPLINE;
	}
	
}

// OESketcher member functions implementation ends
/////////////////////////////////////////////////////////////////////

