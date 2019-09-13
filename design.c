#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.14

void nightSky (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	
	float a, b, j;

	for ( j = 0; j < (2 * pi); j += 0.001)
	{
		a = 400 * cos(j);
		b = 400 * sin(j);
		glVertex2i(a, b);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	float x, y, i;

	for ( i = 0; i < (2 * pi); i += 0.001)
	{
		x = 300 * cos(i);
		y = 300 * sin(i);
		glVertex2i(x, y);
	}
	glEnd();

	glColor4f(0,0,0,1);
	glBegin(GL_POLYGON);		//black 2nd half
		glVertex2i(780,0);
		glVertex2i(780,-420);
		glVertex2i(-780,-420);
		glVertex2i(-780, 0);

	glEnd();

	glFlush();
}


void myInit (void)
{
	glClearColor(0.05, 0., 0.1, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// setting window dimension in X- and Y- direction  and the origin(0,0) is the centre of the screen
	gluOrtho2D(-780, 780, -420, 420);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Night Sky");
    glutDisplayFunc(nightSky);
    //glutMouseFunc(mouse);
    myInit();
    glutMainLoop();
    return 0;
}
