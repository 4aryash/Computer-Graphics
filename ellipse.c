#include<GL/glut.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define pi 3.142857

float rad, DEG2RAD;
void init(void){
  glClearColor(1.0,0.7,0.0,0.0);    //background is set to a shade of yellow
  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,600,0,600);
}

void ellipse(float radiusX, float radiusY)
{
   int i;

   glBegin(GL_LINE_LOOP);

   for(i=0;i<360;i++)
   {
      rad = i*DEG2RAD;
      glVertex2f(cos(rad)*radiusX,
                  sin(rad)*radiusY);
   }

   glEnd();
   glFlush();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(600,600);
  glutCreateWindow("Ellipse");

  init();
  glutDisplayFunc(ellipse);    //line function is called
  glutMainLoop();
  return 0;
}
