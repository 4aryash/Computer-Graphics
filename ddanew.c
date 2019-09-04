#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float X1,X2,Y1,Y2,x,y;

void init(void)
{
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

void Line(){

	float dy,dx,steps,k,Xincrement,Yincrement;

	dx=X2-X1;
	dy=Y2-Y1;

	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	}
	else
		steps = abs(dy);

	Xincrement = dx/steps;
	Yincrement = dy/steps;

	x= X1;
	y=Y1;

	glBegin(GL_LINES);
		glVertex2i(x,y);
	glEnd();

	for (k=0 ; k<=steps; k++){
		x= x + Xincrement;
		y= y + Yincrement;
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
	}
	glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100,100);
  glutCreateWindow ("y = mx + c");
  init();
  glutDisplayFunc();
  //glutMouseFunc(mousePt);   //mousePt function is called
  glutMainLoop();
  return 0;
}
