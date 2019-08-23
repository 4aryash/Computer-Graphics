#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>

void hello(){
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1);

	glBegin(GL_POLYGON);			//ground
	glColor4f(0,0.3,0,1);
		glVertex2i(0,0);
		glVertex2i(0,150);
		glVertex2i(640,150);
		glVertex2i(640,0);
	glEnd();

	glBegin(GL_POLYGON);			//left side block
	glColor4f(1,0,0,1);
		glVertex2i(190,50);
	glColor4f(0,1,0,1);
		glVertex2i(190,240);
	glColor4f(0,0,1,1);
		glVertex2i(90,240);
	glColor4f(1,1,1,1);
		glVertex2i(90,50);
	glEnd();

	glBegin(GL_POLYGON);			//middle block
	glColor4f(0,1,0,1);
		glVertex2i(400,240);
	glColor4f(0,0,1,1);
		glVertex2i(400,50);
	glColor4f(0,0,1,1);
		glVertex2i(200,50);
	glColor4f(0,1,0,1);
		glVertex2i(200,240);
	glEnd();

	glBegin(GL_POLYGON);			//right side block
	glColor4f(1,0,0,1);
		glVertex2i(410,50);
	glColor4f(0,1,0,1);
		glVertex2i(410,240);
	glColor4f(0,0,1,1);
		glVertex2i(510,240);
	glColor4f(1,1,1,1);
		glVertex2i(510,50);
	glEnd();

	//glColor4f(0.007,0.08,0.2,1);
	glBegin(GL_TRIANGLES);			//top triangle
	glColor4f(0,1,0,1);
		glVertex2i(400,250);
	glColor4f(0,1,0,1);
		glVertex2i(200,250);
	glColor4f(1,0,0,1);
		glVertex2i(300,350);
	glEnd();

	glColor4i(0,0,0,1);
	glBegin(GL_POLYGON);			//top line ~ flag pole
		glVertex2f(299.5,349);
		glVertex2f(301.5,349);
		glVertex2f(301.5,400);
		glVertex2f(299.5,400);
	glEnd();


	glColor4f(1.0,0.3,0.03,1);
	glBegin(GL_POLYGON);			//top block ~ flag saffrom
		glVertex2i(299,400);
		glVertex2i(315,400);
		glVertex2i(315,395);
		glVertex2i(299,395);
	glEnd();


	glColor4f(1,1,1,1);
	glBegin(GL_POLYGON);			//top block ~ flag white left block
		glVertex2i(299,395);
		glVertex2i(305,395);
		glVertex2i(305,390);
		glVertex2i(299,390);
	glEnd();
	glColor4f(0,0,1,1);
	glBegin(GL_POLYGON);			//top block ~ flag blue centre block
		glVertex2i(305,395);
		glVertex2i(309,395);
		glVertex2i(309,390);
		glVertex2i(305,390);
	glEnd();
	glColor4f(1,1,1,1);
	glBegin(GL_POLYGON);			//top block ~ flag white right block
		glVertex2i(309,395);
		glVertex2i(315,395);
		glVertex2i(315,390);
		glVertex2i(309,390);
	glEnd();


	glColor4f(0,0.8,0,1);
	glBegin(GL_POLYGON);			//top block ~ flag green
		glVertex2i(299,390);
		glVertex2i(315,390);
		glVertex2i(315,385);
		glVertex2i(299,385);
	glEnd();


glFlush();
}


void init(){
    glClearColor(1.0,0.9,0.7,0.0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("WHITE-HOUSE DOWN.");
    glutDisplayFunc(hello);
    //glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
