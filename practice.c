#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.14

void nightSky (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON); 
	float x, y, i; 
	
	for ( i = 0; i < (2 * pi); i += 0.001) 
	{ 
		x = 400 * cos(i); 
		y = 400 * sin(i); 
		glVertex2i(x, y); 
	} 
	glEnd(); 

	glColor4f(0,0,0,1);
	glBegin(GL_POLYGON);		//black 2nd half
		glVertex2i(780,0);
		glVertex2i(780,-420);
		glVertex2i(-780,-420);
		glVertex2i(-780, 0);

/*
	glColor4f(0,1,0,1);
	glBegin(GL_POLYGON);		//green strip
		glVertex2i(780,10);
		glVertex2i(780,0);
		glVertex2i(-780, 0);
		glVertex2i(-780,-10);

	glColor4f(0,0,1,1);
	glBegin(GL_LINES);
		glVertex2i(780,5);
		glVertex2i(0,5);
		glVertex2i(0,-50);
		glVertex2i(780,-50);
		glVertex2i(780,-25);
		glVertex2i(1,-25);
		glVertex2i(1,4);
		glVertex2i(195,4);
		glVertex2i(195,-49);
		glVertex2i(585,-49);
		glVertex2i(585,4);
	glEnd();
*/

	glEnd();

	glFlush(); 
} 


void myInit (void) 
{ 
	glClearColor(0.05, 0.05, 0.05, 1.0); 
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
