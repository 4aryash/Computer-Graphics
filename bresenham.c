#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

int count =0;
float arrx[5];
float arry[5];
float des=0.0;
float dx=0, dy=0;
float pi=0;
float pf=0;
float m=0;
float x = 0;
float y = 0;

void init(void)
{
  glClearColor(1.0,0.7,0.0,0.0);    //background is set to a shade of yellow
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}


void slopedisplay(float m, float pi)
{
  char buf[50];
  gcvt(m, 10, buf);
  char *c;
  glRasterPos2f(300,40);
  for(c = buf; *c!='\0';c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
  }
  glFlush();

  char buf2[50];
  gcvt(pi, 10, buf2);

  glRasterPos2f(300,60);
  for(c = buf2; *c!='\0';c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
  glFlush();
}

void deltaDisplay(float dx, float dy)
{
  char bufx[50];
  gcvt(dx, 10, bufx);
  char *c;
  //glRasterPos2f(400,40);
  for(c = bufx; *c!='\0';c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
  glFlush();

  char bufy[50];
  gcvt(dy, 10, bufy);
  //glRasterPos2f(400,40);
  for(c = bufy; *c!='\0';c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
  glFlush();
}

void display(){
    x = arrx[count-2];
    y = 500-arry[count-2];
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.01,0.24);
    glBegin(GL_POLYGON);
    for(double i=0; i<2*3.14; i+=(2*3.14)/100)
    {
      glVertex2f((arrx[count-1])+cos(i)*5, (500-arry[count-1])+sin(i)*5);
    }
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    for(double i=0; i<2*3.14; i+=(2*3.14)/100)
    {
      glVertex2f((arrx[count-2])+cos(i)*5, (500-arry[count-2])+sin(i)*5);
    }
    glEnd();
    glFlush();

    //printf("x0=%f, y0=%f",arrx[count-2],500-arry[count-2]);
    //printf(" x1=%f, y1=%f\n",arrx[count-1],500-arry[count-1]);
    dy = (500-arry[count-1])-(500-arry[count-2]);
    dx = (arrx[count-1]-arrx[count-2]);
    deltaDisplay(dx,dy);
    m = dy/dx;
    pi = (2*dy) - dx;
    slopedisplay(m, pi);
    if(m>=0 && m<1)
    {
      while(x<=arrx[count-1])
      {
        if(pi>=0)
        {
            x = x+1;
            y = y+1;
            glColor4f(0.0,0.5,1.0,0.0);
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
            pi = pi + (2*dy - 2*dx);
            //xk+1, yk+1
        }
        else if(pi<0)
        {
           x = x+1;
           y = y;
           glColor4f(1.0,0.5,0.2,0.0);
           glBegin(GL_POINTS);
           glVertex2f(x,y);
           glEnd();
           //xk+1, yk+1
          pi = pi + 2*dy;
        }
        //printf("pi=%f\n",pi);
      }
      glFlush();
    }

    else if(m>1)
    {
      while(y<=500-arry[count-1])
      {
        if(pi>=0)
        {
            y = y+1;
            x = x+1;
            glColor4f(1.0,0.5,0.2,0.0);
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
            pi = pi + (2*dx - 2*dy);
            //xk+1, yk+1
        }
        else if(pi<0)
        {
           y = y+1;
           x = x;
           glColor4f(1.0,0.5,0.2,0.0);
           glBegin(GL_POINTS);
           glVertex2f(x,y);
           glEnd();
           //xk+1, yk+1
          pi = pi + 2*dx;
        }
        printf("pi=%f\n",pi);
      }
      glFlush();
    }
    else if(m<0 && m>=-1)
    {
      while(x<=arrx[count-1])
      {
        if(pi>=0)
        {
            x = x+1;
            y = y;
            glColor4f(1.0,0.5,0.2,0.0);
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
            pi = pi + (2*dy - 2*dx);

            //xk+1, yk+1
        }
        else if(pi<0)
        {
           x = x+1;
           y = y-1;
           glColor4f(1.0,0.5,0.2,0.0);
           glBegin(GL_POINTS);
           glVertex2f(x,y);
           glEnd();
           //xk+1, yk+1
          pi = pi + 2*dy;
        }
        printf("pi=%f\n",pi);
      }
      glFlush();
    }

}


void coordinates(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    arrx[count]=x;
    arry[count]=y;
    count= count+1;
    if(count%2==0)
    {
        display();
    }

  }
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Bresenham Line Drawing");
    //glutDisplayFunc(display);
    //glutKeyboardFunc(move);
    glutMouseFunc(coordinates);
    init();
    glutMainLoop();
    return 0;
}
