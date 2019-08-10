#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>

void hello(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 0.8, 0.7,0.1);

	glColor4f(0.01,0.1,0.3,1);
	glBegin(GL_POLYGON);			//left side block
		glVertex2i(190,0);
		glVertex2i(190,190);
		glVertex2i(90,190);
		glVertex2i(90,0);
	glEnd();

	glColor4f(0.01,0.1,0.3,1);
	glBegin(GL_POLYGON);			//middle block
		glVertex2i(400,190);
		glVertex2i(400,00);
		glVertex2i(200,00);
		glVertex2i(200,190);
	glEnd();

	glColor4f(0.01,0.1,0.3,1);
	glBegin(GL_POLYGON);			//right side block
		glVertex2i(410,0);
		glVertex2i(410,190);
		glVertex2i(510,190);
		glVertex2i(510,00);
	glEnd();

	glColor4f(0.01,0.1,0.3,1);
	glBegin(GL_TRIANGLE_FAN);			//top triangle
		glVertex2i(400,200);
		glVertex2i(200,200);
		glVertex2i(300,300);
	glEnd();
	
	glColor4i(1,0,0,1);
	glBegin(GL_LINE_LOOP);			//top line ~ flag pole
		glVertex2f(299.5,299);
		glVertex2f(301.5,299);
		glVertex2f(301.5,350);
		glVertex2f(299.5,350);
	glEnd();
	
	
	
	
	
	glColor4f(1.0,0.3,0.03,1);
	glBegin(GL_POLYGON);			//top block ~ flag saffrom
		glVertex2i(299,350);
		glVertex2i(315,350);
		glVertex2i(315,345);
		glVertex2i(299,345);
	glEnd();
	
	
	glColor4f(1,1,1,1);
	glBegin(GL_POLYGON);			//top block ~ flag white left block
		glVertex2i(299,345);
		glVertex2i(305,345);
		glVertex2i(305,340);
		glVertex2i(299,340);
	glEnd();
	glColor4f(0,0,1,1);
	glBegin(GL_POLYGON);			//top block ~ flag blue centre block
		glVertex2i(305,345);
		glVertex2i(309,345);
		glVertex2i(309,340);
		glVertex2i(305,340);
	glEnd();
	glColor4f(1,1,1,1);
	glBegin(GL_POLYGON);			//top block ~ flag white right block
		glVertex2i(309,345);
		glVertex2i(315,345);
		glVertex2i(315,340);
		glVertex2i(309,340);
	glEnd();
	
	
	glColor4f(0,0.8,0,1);
	glBegin(GL_POLYGON);			//top block ~ flag green
		glVertex2i(299,340);
		glVertex2i(315,340);
		glVertex2i(315,335);
		glVertex2i(299,335);
	glEnd();

	
	
	
	glFlush();
}


void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("WHITE-HOUSE DOWN.");
    glutDisplayFunc(hello);
    //glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
