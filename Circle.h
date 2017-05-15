#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "Shapes.h"
#include "Color.h"
class Circle : public Shapes
{
public:
	
	Circle(const double x_in, const double y_in, const double radius, const Color &colorIn);
	//std::vector(double) in;
	virtual void paint() const;
protected:
	double radius;
	Color color;
};

#endif