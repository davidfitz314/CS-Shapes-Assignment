#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "Shapes.h"
#include "Color.h"

class Rectangle : public Shapes
{
public:
	Rectangle(const double x_in, const double y_in, const double zx_in, const double zy_in, const Color &colorIn);
	virtual void paint() const;
protected:
	double zx, zy;
	Color color;
};

#endif