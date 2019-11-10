#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int h,k,r;
float a,b;

void scanline(int,int);
void ellipse(void);
void axis(void);

void display(void)
 {
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.01,0.24);
 glBegin(GL_POINTS);
 ellipse();
 glEnd();
 glFlush();
 }

void scanline(int ax, int by)
{
 int ars;
 for(ars=h+ax ; ars>=(h-ax) ; ars--)
 glVertex2s(ars,by);
}

void ellipse(void)
{
 double I,J;
 int i,j;
 glClear (GL_COLOR_BUFFER_BIT);
 glBegin(GL_POINTS);
 glVertex2s(h,k);

 for( i=0 ; i<=a ; i+=1)
 {
 J=sqrt(1 - (i*i)/(a*a))*b;
 j=(int)(J);
 glVertex2s(h+i,k+j);
 glVertex2s(h-i,k+j);
 glVertex2s(h-i,k-j);
 glVertex2s(h+i,k-j);
 scanline(i, j);
 scanline(i,-j);

 }
 glEnd();
 axis();
 glVertex3s(h,k,-25);
}

void axis(void)   //making of the x and y axis
{
 int i;
 glColor3f (1.0, 1.0, 1.0);
 for(i=-100 ; i<=100 ; i++)
 {
 glVertex2s(i,0);
 glVertex2s(0,i);
 }
 for(i=-2; i<=2 ; i++)
 {
 glVertex2s(95+i,4+i);
 glVertex2s(95-i,4+i);
 }
 for(i=0; i<=2 ; i++)
 {
 glVertex2s(4+i,95+i);
 glVertex2s(4-i,95+i);
 glVertex2s(4,95-i);
 }
}

void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 printf("Origin of ellipse:\n");
 scanf("%d %d",&h,&k);
 printf("Values of a and b:\n");
 scanf("%f %f",&a,&b);

 glutCreateWindow ("Scan Line Fill");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
