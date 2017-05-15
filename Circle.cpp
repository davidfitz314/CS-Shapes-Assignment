#include "Circle.h"
#include <cmath>
#ifdef _WIN32
#include "glut.h"
#else
#include <GL/glut.h>
#endif


Circle::Circle(const double x_in, const double y_in, const double radius_in, const Color &colorIn)
	: Shapes(x_in, y_in), radius(radius_in), color(colorIn)
{
}

void Circle::paint() const
{

  
	glColor3d(this->color.r, this->color.g, this->color.b);
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double x = this->x + this->radius * cos(theta);
		double y = this->y + this->radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}