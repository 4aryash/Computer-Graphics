#include<GL/glut.h>
#include<stdio.h>
int x1,y1,x2,y2;

void init(void){
  glClearColor(1.0,0.7,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,500,0,500);
}

void Line(void){
  glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
  glEnd();

}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){
  if(button == GLUT_LEFT_BUTTON && action==GLUT_DOWN)
  {
      glClear(GL_COLOR_BUFFER_BIT);
      x1=xMouse;
      y1=500-yMouse;

      glPointSize(10);

      glBegin(GL_POINTS);
        glColor3f(1.0,0.01,0.24);
        glVertex2i(x1,y1);
      glEnd();
      glFlush();
      //plotpoint(x1,y1);
      printf("Points: %d,%d\n",x1,y1);
  }
}


int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("Locate Points");

  init();
  //glutDisplayFunc(mousePtPlo);
  glutMouseFunc(mousePtPlot);
  glutMainLoop();
  return 0;
}
