// C program to demonstrate
// drawing a circle using
// OpenGL
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
float x=0, y=0, i, r;

// function to initialize
void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
//	glPointSize(1.0);
//	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// setting window dimension in X- and Y- direction
//	gluOrtho2D(-780, 780, -420, 420);
}

void circle (void)
{

for (r=0.0; r<=1.0; r+=0.001)
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

void mouseClick(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		circle();
	}
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laal Tika.");
	myInit();

	glutDisplayFunc(circle);
	glutMouseFunc(mouseClick);
	glutMainLoop();
}
