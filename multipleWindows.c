#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
# define pi 3.142857
float x=0, y=0, i, r;

void circle (void)
{

for (r=0.0; r<=1.0; r+=0.001)		//'+' maximizes the circle
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for ( i = 0; i < (2 * pi); i += 0.0001)
	{
		x = r * cos(i);
		y = r * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}
}

void circle1 (void)
{

for (r=1.0; r>=0.0; r-=0.001)		//'-' minimizing the circle
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for ( i = 0; i < (2 * pi); i += 0.0001)
	{
		x = r * cos(i);
		y = r * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}
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

 GLint WindowID1, WindowID2, WindowID3, WindowID4;       // window ID numbers
 glutInitWindowSize(685.0, 340.0);           // set a window size
 glutInitWindowPosition(0,0);              // set a window position
 WindowID1 = glutCreateWindow("CCTV 1"); // Create window 1
 glutDisplayFunc(circle);               //calling the circle maximizing function

 glutInitWindowSize(685.0, 340.0);           // set a window size
 glutInitWindowPosition(685,0);             // set a window position
 WindowID2 = glutCreateWindow("CCTV 2"); // Create window 2
 glutDisplayFunc(circle1);               //calling the circle maximizing function

 glutInitWindowSize(685.0, 340.0);           // set a window size
 glutInitWindowPosition(0,405);             // set a window position
 WindowID3 = glutCreateWindow("CCTV 3"); // Create window 2

 glutInitWindowSize(685.0, 340.0);           // set a window size
 glutInitWindowPosition(685,405);             // set a window position
 WindowID4 = glutCreateWindow("CCTV 4"); // Create window 2

 init ();
 glutMainLoop();
 return 0;
}
