#include<GL/glut.h>
#include<iostream>
using namespace std;

void init(void){
  glClearColor(0.0,0.6,0.7,0.0);
  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,500,0,500);
}

void LineSegment(void){

  glColor3f(1,1.0,1.0);
  glPointSize(5);

  glBegin(GL_POINTS);
  glColor3f(1,0,1.0);
  glVertex2i(10,145);
  glColor3f(1,0,0);
  glVertex2i(10,15);
  glVertex2i(180,15);
  glVertex2i(180,145);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1,1,1);
  glVertex2i(10,145);
  glVertex2i(180,15);

  glVertex2i(10,145);
  glVertex2i(95,90);

  glVertex2i(10,145);
  glVertex2i(85,80);

  glVertex2i(85,80);
  glVertex2i(10,15);

  glVertex2i(10,15);
  glVertex2i(95,70);

  glVertex2i(95,70);
  glVertex2i(180,15);

  glVertex2i(180,15);
  glVertex2i(105,80);

  glVertex2i(105,80);
  glVertex2i(180,145);

  glVertex2i(95,90);
  glVertex2i(180,145);

  glVertex2i(10,15);
  glVertex2i(180,145);
  glEnd();

  glFlush();
}
int x1;
int yy;
void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){
  if(button == GLUT_LEFT_BUTTON && action==GLUT_DOWN)
  {
      glClear(GL_COLOR_BUFFER_BIT);
      x1=xMouse;
      yy=500-yMouse;

      glPointSize(10);

      glBegin(GL_POINTS);
      glColor3f(1,0,0);
      glVertex2i(x1,yy);
      glEnd();
      LineSegment();
      glFlush();
      //plotpoint(x1,y1);
      cout<<"First point is: "<<x1<<"and"<<yy;

  }
}


int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("Sample Programs");

  init();
  glutDisplayFunc(LineSegment);
  glutMouseFunc(mousePtPlot);
  glutMainLoop();
  return 0;
}
