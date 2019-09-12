#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

int count =0;
float arrx[5];
float arry[5];
float des=0.0;
float dx=0, dy=0;
float m=0;

void init(void)
{

    glClearColor(1.7, 0.7, 0.0, 0.0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);

}


void slopedisplay(char *s)
{
  char *c;
  glRasterPos2f(200,470);   //coordinates where the slope of the line will be displayed
  for(c = s; *c!='\0';c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);    //helvetica font with font size 18
  }
  glFlush();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.01,0.24);
    glBegin(GL_POLYGON);

    for(double i=0; i<2*3.14; i+=(2*3.14)/100)
    {
      glVertex2f((arrx[1])+cos(i)*5, (500-arry[1])+sin(i)*5);
    }
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    for(double i=0; i<2*3.14; i+=(2*3.14)/100)
    {
      glVertex2f((arrx[0])+cos(i)*5, (500-arry[0])+sin(i)*5);
    }
    glEnd();
    glFlush();

    m  = ((500-arry[0])-(500-arry[1]))/(arrx[0]-arrx[1]);
    char buf[50];
    gcvt(m, 10, buf);

    //slopedisplay("Aaryash Sinha 002");
    slopedisplay(buf);
    if(m<=1 && m>=-1)
    {
        des = arrx[1]- arrx[0];
    }
    else if(m>1 || m<-1)
    {
        des = (500-arry[1])-(500-arry[0]);
    }
    if(des>0)
    {
      //add
      dx=arrx[0];
      dy=500-arry[0];
      if(m<=1 && m>=-1)
      {
        while(dx<=arrx[1])
        {
            dx = dx+1;
            dy = dy+m;
            glColor4f(1.0,0.5,0.2,0.0);
            glBegin(GL_POINTS);
            glVertex2f(dx,dy);
            glEnd();
            glFlush();
        }
      }
      else if(m>1 || m<-1)
      {
        while(dy<=500-arry[1])
        {
            dx = dx+1/m;
            dy = dy+1;
            glColor4f(1.0,0.5,0.0,0.0);
            glBegin(GL_POINTS);
            glVertex2f(dx,dy);
            glEnd();
            glFlush();
        }
      }

    }
    else
    {
      //minus
      dx=arrx[0];
      dy=500-arry[0];
      if( m<=1 && m>=-1)
      {
        while(dx!=arrx[1])
        {
            dx = dx-1;
            dy = dy-m;
            glColor4f(1.0,1.0,0.7,0.0);
            glBegin(GL_POINTS);
            glVertex2f(dx,dy);
            glEnd();
            glFlush();
        }

      }
      else if(m>1 || m<-1)
      {
        while(dy!=500-arry[1])
        {
            dx = dx-1/m;
            dy = dy-1;
            glColor4f(1.0,0.0,0.0,0.0);
            glBegin(GL_POINTS);
            glVertex2f(dx,dy);
            glEnd();
            glFlush();
        }
      }
    }
}




/*void move(unsigned char key, int x, int y) {

switch(key){
case 27: glutDestroyWindow(1); break;
case 32: display(); break;
}

}*/

void coordinates(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    arrx[count]=x;
    arry[count]=y;
    count= count+1;
    if(count==2)
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
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA Line");
    //glutDisplayFunc(display);
    //glutKeyboardFunc(move);
    glutMouseFunc(coordinates);
    init();
    glutMainLoop();
    return 0;
}
