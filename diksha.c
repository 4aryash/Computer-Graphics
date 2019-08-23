#include <math.h>
#include <time.h>
#include <GL/glut.h>
int cnt=0;
void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void bound_it(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_it(x+1,y,fillColor,bc);
        bound_it(x-2,y,fillColor,bc);
        bound_it(x,y+2,fillColor,bc);
        bound_it(x,y-2,fillColor,bc);
    }
}


void display(){
    float theta;
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);

    //lower bg
    glColor4f(0.3,0.7,0,1);
     glBegin(GL_POLYGON);
        glVertex2f(0.0,220.0);//w
        glVertex2f(1000.0,220.0);//x
        glVertex2f(1000.0,0.0);//y
        glVertex2f(0.0,0.0);//z
    glEnd();

    //upper bg
    glColor4f(0.2,0,0.5,1);
     glBegin(GL_POLYGON);
        glVertex2f(0.0,220.0);//w
        glVertex2f(1000.0,220.0);//x
        glVertex2f(1000.0,1000.0);//y'
        glVertex2f(0.0,1000.0);//z'
    glEnd();

    //hut triangle
    glColor4f(1,0.2,0,1);
    glBegin(GL_TRIANGLES);
        glVertex2f(200.0,250.0);//b
        glVertex2f(250.0,300.0);//a
        glVertex2f(300.0,250.0);//c
    glEnd();

    //hut lower
    glColor4f(1,1,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(200.0,250.0);//b
        glVertex2f(300.0,250.0);//c
        glVertex2f(300.0,200.0);//d
        glVertex2f(200.0,200.0);//e
    glEnd();


    //doorclose
    if(cnt%2!=0)
    {
     glColor4f(0,0,0,1);
    }
    else
    {
     glColor4f(1,0.5,0,1);

    }

    glBegin(GL_POLYGON);
        glVertex2f(265.0,230.0);//b'
        glVertex2f(225.0,230.0);//c'
        glVertex2f(225.0,200.0);//e'
        glVertex2f(265.0,200.0);//d'
    glEnd();

    if(cnt%2!=0)
    {
     //dooropen
    glColor4f(1,0.5,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(265.0,230.0);//b'
        glVertex2f(240.0,220.0);//c'
        glVertex2f(240.0,190.0);//e'
        glVertex2f(265.0,200.0);//d'

    glEnd();

    }

    //hut
    glColor4f(1,0.4,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(250.0,300.0);//a
        glVertex2f(350.0,300.0);//f
        glVertex2f(400.0,250.0);//g
        glVertex2f(300.0,250.0);//c
    glEnd();

    //hut
    glColor4f(1,0.6,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(300.0,250.0);//c
        glVertex2f(400.0,250.0);//g
        glVertex2f(400.0,200.0);//h
        glVertex2f(300.0,200.0);//d
    glEnd();

    //tree lower
    glColor4f(1,0.7,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(100.0,200.0);//t1
        glVertex2f(120.0,200.0);//t2
        glVertex2f(120.0,150.0);//t3
        glVertex2f(100.0,150.0);//t4
    glEnd();
    //tree top
    glColor4f(0.3,1,0,1);
    glBegin(GL_TRIANGLES);
        glVertex2f(70.0,170.0);//b
        glVertex2f(110.0,250.0);//a
        glVertex2f(150.0,170.0);//c
    glEnd();

     //circle
     glColor4f(1,1,1,1);
     glBegin(GL_POLYGON);
        for(double i=0; i<2*3.14; i+=3.14/30)
        {
        	glVertex2f(100+cos(i)*25, 400+sin(i)*25);
        }
    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		++cnt;
		display();
	}
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(200,200);
    glutCreateWindow("FRIDAY");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
