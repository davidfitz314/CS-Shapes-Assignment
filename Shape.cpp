#include "shape.h"

Shape::Shape()
	: x(-1), y(-1)
{
}

Shape::Shape(const double x_in, const double y_in, const &color_in)
	: x(x_in), y(y_in), color(color_in)
{
}
