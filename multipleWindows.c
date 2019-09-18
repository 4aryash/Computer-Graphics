#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void display(void)
 {
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.01,0.24);
 glBegin(GL_POINTS);
 ellipse();
 glEnd();
 glFlush();
 }

void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

 GLint WindowID1, WindowID2;                  // window ID numbers
 glutInitWindowSize(250.0, 250.0);           // set a window size
 glutInitWindowPosition(50,50);              // set a window position
 WindowID1 = glutCreateWindow("Window One"); // Create window 1

 glutInitWindowSize(500.0, 250.0);           // set a window size
 glutInitWindowPosition(500,50);             // set a window position
 WindowID2 = glutCreateWindow("Window Two"); // Create window 2

 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
