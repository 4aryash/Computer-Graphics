#include<GL/gl.h>
#include<GL/glut.h>

void hello(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0,1);
	glColor4i(1,1,0,0);
	glBegin(GL_TRIANGLES);
		glVertex2i(400,200);
		glVertex2i(200,200);
		glVertex2i(300,300);
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
    glutCreateWindow("Triangle banane ki koshish.");
    glutDisplayFunc(hello);
    //glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
