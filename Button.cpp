#include "Button.h"
#ifdef _WIN32
#include "glut.h"
#else
#include <GL/glut.h>
#endif
#include <cstring>
//#include <cstdlib>

Button::Button()
	: rect(false), tria(false), circ(false), clear(false), exit(false), undo(false)
{
}

bool Button::Pushed(int in_x, int in_y)
{
	if ((in_x >= 10 && in_x <= 110) && (in_y >= 10 && in_y <= 50)){
		this->circ=true;
		this->rect=false;
		this->tria=false;
		this->clear=false;
		this->exit=false;
		this->undo=false;
		return true;
	}
	if ((in_x >= 10 && in_x <= 110) && (in_y >= 60 && in_y <= 100)){
		this->tria=true;
		this->circ=false;
		this->rect=false;
		this->clear=false;
		this->exit=false;
		this->undo=false;
		return true;
	}
	if ((in_x >= 10 && in_x <= 110) && (in_y >= 110 && in_y <= 150)){
		this->rect=true;
		this->tria=false;
		this->circ=false;
		this->clear=false;
		this->exit=false;
		this->undo=false;
		return true;
	}
	if ((in_x >= 10 && in_x <= 110) && (in_y >= 160 && in_y <= 200)){
		this->rect=false;
		this->tria=false;
		this->circ=false;
		this->clear=true;
		this->exit=false;
		this->undo=false;
		return true;
	}
	if ((in_x >= 590 && in_x <= 690) && (in_y >= 10 && in_y <= 50)){
		this->circ=false;
		this->rect=false;
		this->tria=false;
		this->clear=false;
		this->exit=true;
		this->undo=false;
		return true;
	}
	if ((in_x >= 10 && in_x <= 110) && (in_y >= 210 && in_y <= 250)){
		this->rect=false;
		this->tria=false;
		this->circ=false;
		this->clear=false;
		this->exit=false;
		this->undo=true;
		return true;
	}
	return false;
	}

char Button::what(){
	if (this->rect){
		return 'r';
	}
	if (this->tria){
		return 't';
	}
	if (this->circ){
		return 'c';
	}
	if (this->clear){
		return 'l';
	}
	if (this->exit){
		return 'x';
	}
	if (this->undo){
		return 'u';
	}
	return '0';
}
void Button::DrawButtons()
{
	
	Rectangle b1 = Rectangle::Rectangle(10, 10, 110, 50, Color(.9, .80, .70));
	b1.paint();

	Rectangle b2 = Rectangle::Rectangle(10, 60, 110, 100, Color(.9, .80, .70));
	b2.paint();

	Rectangle b3 = Rectangle::Rectangle(10, 110, 110, 150, Color(.9, .80, .70));
	b3.paint();

	Rectangle b4 = Rectangle::Rectangle(10, 160, 110, 200, Color(.9, .80, .70));
	b4.paint();

	Rectangle exit = Rectangle::Rectangle(590, 10, 690, 50, Color(.9, .80, .70));
	exit.paint();

	Rectangle und = Rectangle::Rectangle(10, 210, 110, 250, Color(.9, .80, .70));
	und.paint();

	glColor3d(0,0,0);
	DrawText(14,25,"Circle");
	DrawText(14,75,"Triangle");
	DrawText(14,125,"Rectangle");
	DrawText(14,175, "Clear");
	DrawText(594, 25, "Exit");
	DrawText(14, 225, "Undo");
}

void Button::DrawText(double x, double y, const char *string)
{
  void *font = GLUT_BITMAP_9_BY_15;

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