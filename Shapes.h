#ifndef _SHAPES_H_
#define _SHAPES_H_
//#include "Color.h"


class Shapes
{
public:
	Shapes();
	Shapes(const double x_in, const double y_in);
	virtual void paint() const =0;
	
//	virtual std::vector<Point> getPoints() const = 0;
	double x, y;
protected:
//	Color color;
};

#endif