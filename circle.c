#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
# define pi 3.142857
float x=0, y=0, i, r;

// function to initialize
void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'm':			//escape key
			circle1(); //circle1 minimizes on hitting m
		case 27:			//escape key
			circle(); //circle1 maximizes on hitting spacebar
	}
}

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

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laal Tika.");
	myInit();

	glutDisplayFunc(circle);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
