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
	glBegin(GL_LINE_LOOP);
		glVertex2i(0,42);
		glVertex2i(-42,0);
		glVertex2i(-84,0);
		glVertex2i(-84,-50);
		glVertex2i(-90,-50);
		glVertex2i(-90,-60);
		glVertex2i(-84,-60);
		glVertex2i(-84,-70);
		glVertex2i(-90,-70);
		glVertex2i(-90,-80);
		glVertex2i(-84,-80);
		glVertex2i(0,-80);
	glEnd();

	glFlush(); 
} 


void myInit (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
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
