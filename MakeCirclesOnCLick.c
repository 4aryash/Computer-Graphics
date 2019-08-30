#include<GL/glut.h> //includes the opengl, glu, and glut header files
#include<stdlib.h> //includes the standard library header file
#include<stdbool.h>
#define pi 3.142857

int i,j;
float r,g,b,x,y;
bool check=true;

void circle (void)
{

for (r=0.0; r<=1.0; r+=0.001)
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
void mouse(int button, int state, int mX, int mY)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       check=true;

        x = mX;
        y = 480-mY;
        r=0;
        g=0;
        b=0;
        }

   else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)//undo(clear)the drawing
           {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
      check = false;
     }

     glutPostRedisplay();
     }

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'f':			//escape key
			exit(0);
	}
}

void display(void)
{
    glColor3f(r,g,b);
    glPointSize(30);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

if(check)
{
       glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
       glVertex2i(x,y);

  glEnd();
}
    glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);   //sets the width and height of the window in pixels
    glutInitWindowPosition(50,50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("GlutMouseFunc.");

    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
		glutKeyboardFunc(keyboard);
    glutMainLoop();
}
