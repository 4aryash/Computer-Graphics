#include<GL/glut.h>
#include<stdio.h>

void init(void){
  glClearColor(1.0,0.7,0.0,0.0);    //background is set to a shade of yellow
  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,600,0,600);
}




void myNameWillBeDisplayed(char *s)    //string diaplay
{
  char *c;
  glRasterPos2f(400,50);
  for(c = s; *c!='\0';c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
  glFlush();
}

void display(GL_POINTS){
  glColor3f(0,0,0);
  slopedisplay("AARYASH SINHA  002");
  glBegin();
    glVertex2i(200,200);
  glEnd();
}



int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(600,600);
  glutCreateWindow("Locate Points");

  init();
  glutDisplayFunc(display);    //line function is called
  glutMainLoop();
  return 0;
}
