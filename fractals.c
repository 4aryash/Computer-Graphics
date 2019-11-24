#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define dimension 1000 // window size


int levelmax = 7; // maximum level of recursion
int nleaf = 2; // number of leafs per branch
float openness = 1.4; // controls how open the leafs are
float factor = 1.5; // controls how fast branch sizes decrease
float zoom = 1; // zoom of visualization
float offset = 0; // controls how crooked branches are
float windowx = 0.5, windowy = 0.5; // position of center of window


void init (void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void mouse(int button, int state, int x, int y)
{
  y = dimension - y;
  if(button == 0 && state == 1)
  {
    windowx += (x-dimension/2.)/dimension/zoom;
    windowy += (y-dimension/2.)/dimension/zoom;
  }
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
  switch(key) 
  {

    case 'f':
      levelmax += 1;
      glutPostRedisplay();
      break;
    case 'j':
      if(levelmax > 2)
      {
        levelmax -= 1;
        glutPostRedisplay();
      }
      break;
    case 'z':
      zoom *= 1/1.1;
      glutPostRedisplay();
      break;
    case 'x':
      zoom *= 1.1;
      glutPostRedisplay();
      break;
   }
}

void draw_fractal(double x0, double y0, double angle0, int level)
{
  if(level > levelmax) return;
  float r = 0.15/pow(factor,level-1);
  float angle;
  float x, y, cosX, sinX;
  int i;
  for(i = 0; i < nleaf; i++)
  {
    angle = offset + angle0 + i*2*M_PI/nleaf/openness - (nleaf-1)*2*M_PI/nleaf/openness/2;
    cosX = cos(angle);
    sinX = sin(angle);
    x = x0 + r*cosX;
    y = y0 + r*sinX;
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x, y);
    glEnd();
    draw_fractal(x, y, atan2((y-y0), (x-x0)), level+1);
  }
}


void image(void)
{
  float tmp = 0.5/zoom;
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  gluOrtho2D(windowx-tmp, windowx+tmp, windowy-tmp, windowy+tmp);
  draw_fractal(0.5, 0.5, M_PI/2, 1);
  glFlush();
}

int main (int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(dimension, dimension);
  glutInitWindowPosition(200, 0);
  glutCreateWindow("Recurring H");
  init();
  glutDisplayFunc(image);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
