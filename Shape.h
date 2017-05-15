#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "Color.h"


class Shape
{
public:
	Shape();
	Shape(const double x_in, const double y_in, const &color_in);
	virtual void paint() const;
//	virtual std::vector<Point> getPoints() const = 0;
	double x, y;
protected:
	Color color;
};

#endif