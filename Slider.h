#ifndef _SLIDER_H_
#define _SLIDER_H_
#include "Circle.h"
#include "Color.h"

class Slider 
{
public:
	Slider(const Color &colorIn);
	bool Color_Push(int in_x, int in_y);
	void Draw_Slider();
	void DrawText(double x, double y, const char *string);
	double red, green, blue;
	double r, g, b;
	double getRed();
	double getGreen();
	double getBlue();
protected:
	Color color;

};
#endif