#include "Slider.h"
#ifdef _WIN32
#include "glut.h"
#else
#include <GL/glut.h>
#endif
#include <cstring>
#include "Triangle.h"
Slider::Slider(const Color &colorIn)
	: red(1.0), green(1.0), blue(1.0), color(colorIn)
{
}

bool Slider::Color_Push(int in_x, int in_y)
{
	if ((in_x > 630 && in_x < 660) && (in_y > 435 && in_y < 465))
	{
		this->color.r += .05;
		return true;
	}
	if ((in_x > 630 && in_x < 660) && (in_y > 385 && in_y < 415))
	{
		this->color.r -= .05;
		return true;
	}
	if ((in_x > 630 && in_x < 660) && (in_y > 335 && in_y < 365))
	{
		this->color.g += .05;
		return true;
	}
	if ((in_x > 630 && in_x < 660) && (in_y > 285 && in_y < 315))
	{
		this->color.g -= .05;
		return true;
	}
	if ((in_x > 630 && in_x < 660) && (in_y > 235 && in_y < 265))
	{
		this->color.b += .05;
		return true;
	}
	if ((in_x > 630 && in_x < 660) && (in_y > 185 && in_y < 215))
	{
		this->color.b -= .05;
		return true;
	}
	return false;
}
void Slider::Draw_Slider()
{
	
	Circle redUp = Circle(645, 450, 20, Color(1, 0, 0));
	redUp.paint();
	
	Circle redDown = Circle(645, 400, 20, Color(1, 0, 0));
	redDown.paint();
	
	Circle greenUp = Circle(645, 350, 20, Color(0, 1, 0));
	greenUp.paint();
	
	Circle greenDown = Circle(645, 300, 20, Color(0, 1, 0));
	greenDown.paint();
	
	Circle blueUp = Circle(645, 250, 20, Color(0, 0, 1));
	blueUp.paint();
	
	Circle blueDown = Circle(645, 200, 20, Color(0, 0, 1));
	blueDown.paint();
	
	Circle around = Circle(645, 125, 38, Color(.1,.1,.1));
	around.paint();
	
	Circle around2 = Circle(645, 125, 25, Color(1, 1, 1));
	around2.paint();
	//slider text characters
	glColor3d(0,0,0);
	DrawText(639, 444, "+");
	DrawText(639, 394, "-");
	DrawText(639, 344, "+");
	DrawText(639, 294, "-");
	DrawText(639, 244, "+");
	DrawText(639, 194, "-");
	//changing color not constant
	
	
	//glColor3d(this->color.r, this->color.g, this->color.b);
	
	Triangle cPick = Triangle(625, 100, 665, 100, 645, 160, Color(this->color.r, this->color.g, this->color.b));
	cPick.paint();
	Triangle cPick2 = Triangle(625, 155, 665, 155, 645, 95, Color(this->color.r, this->color.g, this->color.b));
	cPick2.paint();
}

void Slider::DrawText(double x, double y, const char *string)
{
  void *font = GLUT_BITMAP_TIMES_ROMAN_24;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
	
  int len, i;
  glRasterPos2d(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) 
    {
      glutBitmapCharacter(font, string[i]);
    }

  glDisable(GL_BLEND);
}
double Slider::getRed()
{
	return (this->color.r);
}
double Slider::getGreen()
{
	return (this->color.g);
}
double Slider::getBlue()
{
	return (this->color.b);
}
