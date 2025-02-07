#pragma once

#include <wx/glcanvas.h>
#include <wx/wx.h>

#include "SideBar.hpp"
#include "NavMesh/NavMesh.hpp"

class DrawPane : public wxGLCanvas
{
public:
	DrawPane(wxWindow *parent, SideBar *sideBar, NavMesh *navMesh);
	~DrawPane();

	void paintEvent(wxPaintEvent&);
	
	void leftMouseButtonDownEvent(wxMouseEvent &event);
	void leftMouseButtonUpEvent(wxMouseEvent &event);
	
	void rightMouseButtonDownEvent(wxMouseEvent &event);
	void rightMouseButtonUpEvent(wxMouseEvent &event);
	
	void mouseMotionEvent(wxMouseEvent &event);
	
	void render();

private:
	wxGLContext *glContext;
	SideBar *sideBar;
	NavMesh *navMesh;

	wxToolTip *nodeInfoToolTip;

	DECLARE_EVENT_TABLE()
};