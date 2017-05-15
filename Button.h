#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "Rectangle.h"

class Button
{
public:
	Button();
	bool Pushed(int in_x, int in_y);
	
	void DrawButtons();
	void DrawText(double x, double y, const char *string);
	bool rect, tria, circ, clear, exit, undo;
	char what();
protected:
	int in_x, in_y;
	

	
	/*
	int rect_x, rect_y, rect_x2, rect_y2;
	int tri_x, tri_y, tri_x2, tri_y2;
	int circ_x, circ_y, circ_x2, circ_y2;
	*/
};

#endif