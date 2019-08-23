#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>

void hello(){
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1);

  glColor4f(0,0,0,1);
	glBegin(GL_POLYGON);			//1st black block
		glVertex2i(715,410);
    glVertex2i(-715,410);
    glVertex2i(-715,-410);
    glVertex2i(715,-410);
  glEnd();

  glColor4f(1,1,1,1);
  glBegin(GL_POLYGON);			//2nd white block
    glVertex2i(710,405);
    glVertex2i(-710,405);
    glVertex2i(-710,-405);
    glVertex2i(710,-405);
  glEnd();

  glColor4f(0,0,0,1);
  glBegin(GL_POLYGON);			//3rd black block
    glVertex2i(700,400);
    glVertex2i(-700,400);
    glVertex2i(-700,-400);
    glVertex2i(700,-400);
  glEnd();

glFlush();
}


void init(){
    glClearColor(0.9,0.9,0.9,0.0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-780, 780, -420, 420);
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
