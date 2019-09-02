#include<GL/glut.h>
#include<stdio.h>
int x1,y1,x2,y2;

void init(void){
  glClearColor(1.0,0.7,0.0,0.0);    //background is set to a shade of yellow
  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,600,0,600);
}

void mousePt(GLint button, GLint action, GLint xMouse, GLint yMouse){
  if(button == GLUT_LEFT_BUTTON && action==GLUT_DOWN)     //on clicking the left mouse button, the first coordinates x1,y1 are formed.
  {
      //glClear(GL_COLOR_BUFFER_BIT);
      x1 = xMouse;        //x coordinate is formed from the bottom-left screen.
      y1 = 600-yMouse;    //y coordinate is formed from the top-left screen, so we subtract the window-size from the y-coordinates

      glPointSize(10);    //size of the point formed

      glBegin(GL_POINTS);
        glColor3f(1.0,0.01,0.24);
        glVertex2i(x1,y1);
      glEnd();
      glFlush();
      printf("Left Click at: (%d,%d)\n",x1,y1);   //a point red in color, is formed
  }

  if(button == GLUT_RIGHT_BUTTON && action==GLUT_DOWN)
  {
      //glClear(GL_COLOR_BUFFER_BIT);

      x2 = xMouse;        //x coordinate is formed from the bottom-left screen.
      y2 = 600-yMouse;    //y coordinate is formed from the top-left screen, so we subtract the window-size from the y-coordinates

      glPointSize(10);

      glBegin(GL_POINTS);
        glColor3f(0.0,0.24,0.01);
        glVertex2i(x2,y2);
      glEnd();
      Line();

      glFlush();
      printf("Right Click at: (%d,%d)\n\n",x2,y2);    //a point blue in color, is formed
  }
}

void Line(void){
  glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);    //a line is formed with amongst these points.
  glEnd();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(600,600);
  glutCreateWindow("Locate Points");

  init();
  glutDisplayFunc(Line);    //line function is called
  glutMouseFunc(mousePt);   //mousePt function is called
  glutMainLoop();
  return 0;
}
