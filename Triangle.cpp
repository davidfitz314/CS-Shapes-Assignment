#include "Triangle.h"
#include <cmath>
#ifdef _WIN32
#include "glut.h"
#else
#include <GL/glut.h>
#endif

Triangle::Triangle(const double x_in, const double y_in, const double x2_in, const double y2_in, const double zx_in, const double zy_in, const Color &colorIn)
	: Shapes(x_in, y_in), x2(x2_in), y2(y2_in), zx(zx_in), zy(zy_in), color(colorIn)
{
}

void Triangle::paint() const
{
	//modify color picking here
	glColor3d(this->color.r, this->color.g, this->color.b);
  
	glBegin(GL_TRIANGLES);
	glVertex2d(this->x,this->y);
	glVertex2d(this->x2,this->y2);
	glVertex2d(this->zx,this->zy);
	
	glEnd();
}
