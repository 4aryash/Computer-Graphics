#include<GL/glut.h>
#include<stdio.h>
int x1,y1,x2,y2;

void init(void){
  glClearColor(1.0,0.7,0.0,0.0);    //background is set to a shade of yellow
  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,600,0,600);
}

void drawEllipse(float xc, float yc, float x, float y)
{
  glFlush();
    int p1[] = {(int)xc+x, (int)yc+y};
    int p2[] = {(int)xc-x, (int)yc+y};
    int p3[] = {(int)xc+x, (int)yc-y};
    int p4[] = {(int)xc-x, (int)yc-y};
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
}

void ellipseMidpoint(float xc, float yc, float rx, float ry)
{
    float rxSq = rx * rx;
    float rySq = ry * ry;
    float x = 0, y = ry, p;
    float px = 0, py = 2 * rxSq * y;
    drawEllipse(xc, yc, x, y);

    p = rySq - (rxSq * ry) + (0.25 * rxSq);
    while (px < py)
    {
        x++;
        px = px + 2 * rySq;
        if (p < 0)
            p = p + rySq + px;
        else
        {
            y--;
            py = py - 2 * rxSq;
            p = p + rySq + px - py;
        }
        drawEllipse(xc, yc, x, y);
    }

    p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
    while (y > 0)
    {
        y--;
        py = py - 2 * rxSq;
        if (p > 0)
            p = p + rxSq - py;
        else
        {
            x++;
            px = px + 2 * rySq;
            p = p + rxSq - py + px;
        }
        drawEllipse(xc, yc, x, y);
    }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(600,600);
  glutCreateWindow("Ellipse");

  init();
  glutDisplayFunc(drawEllipse);    //line function is called
  glutMainLoop();
  return 0;
}
