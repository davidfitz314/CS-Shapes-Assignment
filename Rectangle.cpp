#include "Rectangle.h"
#include <cmath>
#ifdef _WIN32
#include "glut.h"
#else
#include <GL/glut.h>
#endif

Rectangle::Rectangle(const double x_in, const double y_in, const double zx_in, const double zy_in, const Color &colorIn)
	: Shapes(x_in, y_in), zx(zx_in), zy(zy_in), color(colorIn)
{
}

void Rectangle::paint() const
{
	//modify color picking here
	glColor3d(this->color.r, this->color.g, this->color.b);
  
	glBegin(GL_QUADS);
	glVertex2d(this->x,this->y);
	glVertex2d(this->zx,this->y);
	glVertex2d(this->zx,this->zy);
	glVertex2d(this->x,this->zy);
	glEnd();
}
