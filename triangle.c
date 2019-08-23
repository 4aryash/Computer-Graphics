#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>

void hello(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0,1);

	glColor4i(0,0,0,1);
	glBegin(GL_POLYGON);			//left side block
		glVertex2i(190,0);
		glVertex2i(190,190);
		glVertex2i(90,190);
		glVertex2i(90,0);
	glEnd();

	glColor4i(0,0,0,1);
	glBegin(GL_POLYGON);			//middle block
		glVertex2i(400,190);
		glVertex2i(400,00);
		glVertex2i(200,00);
		glVertex2i(200,190);
	glEnd();

	glColor4i(0,0,0,1);
	glBegin(GL_POLYGON);			//right side block
		glVertex2i(410,0);
		glVertex2i(410,190);
		glVertex2i(510,190);
		glVertex2i(510,00);
	glEnd();

	glColor4i(1,0,0,1);
	glBegin(GL_TRIANGLE_FAN);			//top triangle
		glVertex2i(400,200);
		glVertex2i(200,200);
		glVertex2i(300,300);
	glEnd();

	glFlush();
}

/*
void drawLeftCircle()   // the filled one
{
    float radius = 70;
    float twoPI = 2 * 3.14;

    glBegin(GL_TRIANGLE_FAN);

    for (float i = 3.14; i <= twoPI; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glFlush();
}
*/

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
