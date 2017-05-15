#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include "Shapes.h"
#include "Color.h"

class Triangle : public Shapes
{
public:
	Triangle(const double x_in, const double y_in, const double x2_in, const double y2_in, const double zx_in, const double zy_in, const Color &colorIn);
	virtual void paint() const;
protected:
	double x2, y2, zx, zy;
	Color color;
};

#endif