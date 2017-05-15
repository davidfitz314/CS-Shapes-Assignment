// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Button.h"
#include "Slider.h"
#include <vector>
#include <cmath>
#include "MPoints.h"
#ifdef _WIN32
  #include "glut.h"
#else
  #ifdef __APPLE__
    #include <GLUT/glut.h>
  #else
    #include <GL/glut.h>
  #endif
#endif
#include "Color.h"


Button button;

std::vector<double> points;
std::vector<Shapes*> shamon;

std::vector<MPoints*> mpoint;
// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 500;


Color CPick = Color(0.0, 0.0, 0.0);
double r = 0.0;
double g = 0.0;
double b = 0.0;
Slider Slide = Slider(CPick);
// 
// Functions that draw basic primitives
//
/*
void DrawCircle(double x1, double y1, double radius)
{
  glBegin(GL_POLYGON);
  for(int i=0; i<32; i++)
    {
      double theta = (double)i/32.0 * 2.0 * 3.1415926;
      double x = x1 + radius * cos(theta);
      double y = y1 + radius * sin(theta);
      glVertex2d(x, y);
    }
  glEnd();
}

void DrawRectangle(double x1, double y1, double x2, double y2)
{
  glBegin(GL_QUADS);
  glVertex2d(x1,y1);
  glVertex2d(x2,y1);
  glVertex2d(x2,y2);
  glVertex2d(x1,y2);
  glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
  glBegin(GL_TRIANGLES);
  glVertex2d(x1,y1);
  glVertex2d(x2,y2);
  glVertex2d(x3,y3);
  glEnd();
}
*/
// Outputs a string of text at the specified location.
void DrawText(double x, double y, const char *string)
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


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  Color temp = Color(r, g, b);
  
  button.DrawButtons();
  char which = button.what();
  for (unsigned int i = 0; i<points.size(); i+=2){
	MPoints *mice = new MPoints(points[i], points[i+1]);
	mpoint.push_back(mice);
  }
  if (which == 'r' && points.size() == 4){
	Rectangle *rec = new Rectangle(points[0], points[1], points[2], points[3], temp);
	shamon.push_back(rec);
	std::cout << "Rectangele " << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << " " << temp.r << " " << temp.g << " " << temp.b << "\n" << std::endl; 
	points.clear();
  }
  
  if (which == 't' && points.size() == 6){
	Triangle *tri = new Triangle(points[0], points[1], points[2], points[3], points[4], points[5], temp);
	shamon.push_back(tri);
	
	points.clear();
  }
  if (which == 'c' && points.size() == 4){
	Circle *cir = new Circle(points[0], points[1], sqrt((pow((points[0]-points[2]), 2) + pow((points[1]-points[3]), 2))), temp);
	shamon.push_back(cir);
	
	points.clear();
  }

  if (which == 'l'){
	  shamon.clear();
	  points.clear();
	  mpoint.clear();
  }
  if (which == 'x'){
	  exit(0);
  }
  if (which == 'u' && shamon.size() > 0){
	  shamon.pop_back();
	  button.undo = false;

  }
 
  for (unsigned int j = 0; j<mpoint.size(); j++){
	  glColor3d(0,0,0);
	  DrawText(mpoint[j]->mx(), mpoint[j]->my(), "o");
  }
  for (unsigned int i = 0; i<shamon.size(); i++){
	  
	  shamon[i]->paint();
  }
  

  button.DrawButtons();
  Slide.Draw_Slider();
  glutSwapBuffers();
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
  switch (c) 
    {
    case 'q':
    case 27: // escape character means to quit the program
      exit(0);
      break;
    case 'b':
      // do something when 'b' character is hit.
      break;
    default:
      return; // if we don't care, return without glutPostRedisplay()
    }

  glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
  // Reset our global variables to the new width and height.
  screen_x = w;
  screen_y = h;

  // Set the pixel resolution of the final picture (Screen coordinates).
  glViewport(0, 0, w, h);

  // Set the projection mode to 2D orthographic, and set the world coordinates:
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
  // translate pixel coordinates to display coordinates
 
  int xdisplay = x;
  int ydisplay = screen_y - y;
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
		bool value = button.Pushed(xdisplay, ydisplay);
		bool cValue = Slide.Color_Push(xdisplay, ydisplay);
		if (!value && !cValue) {
			points.push_back(xdisplay);
			points.push_back(ydisplay);
			
		}
		if (value && !cValue) {
			points.clear();
		}
		if (cValue && !value){
			
			r = Slide.getRed();
			g = Slide.getGreen();
			b = Slide.getBlue();
			//std::cout << "working" << std::endl;
		}
		
		
//		std::cout << xdisplay << '\n' << ydisplay << std::endl;
    }
   /*
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    {
		
    }
 
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
    {
    }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
    {
    }
	*/
  
  glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
	
	

}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(screen_x, screen_y);
  glutInitWindowPosition(50, 50);

  int fullscreen = 0;
  if (fullscreen) 
    {
      glutGameModeString("800x600:32");
      glutEnterGameMode();
    } 
  else 
    {
      glutCreateWindow("This appears in the title bar");
    }

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);

  glColor3d(0,0,0); // forground color
  glClearColor(1, 1, 1, 0); // background color
  InitializeMyStuff();
  
  glutMainLoop();

  return 0;
}