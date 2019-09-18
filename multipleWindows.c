#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void display(void)
 {
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.01,0.24);
 glBegin(GL_POINTS);
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

 GLint WindowID1, WindowID2, WindowID3;       // window ID numbers
 glutInitWindowSize(685.0, 350.0);           // set a window size
 glutInitWindowPosition(0,0);              // set a window position
 WindowID1 = glutCreateWindow("CCTV 1"); // Create window 1

 glutInitWindowSize(685.0, 350.0);           // set a window size
 glutInitWindowPosition(685,0);             // set a window position
 WindowID2 = glutCreateWindow("CCTV 2"); // Create window 2

 glutInitWindowSize(685.0, 350.0);           // set a window size
 glutInitWindowPosition(0,350);             // set a window position
 WindowID3 = glutCreateWindow("CCTV 3"); // Create window 2

 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
