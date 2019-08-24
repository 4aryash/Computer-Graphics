#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857


void hello(){
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1);

	glBegin(GL_POLYGON);			//road
	glColor4f(0.51,0.54,0.55,1);
		glVertex2i(0,0);
		glVertex2i(0,160);
		glVertex2i(640,160);
		glVertex2i(640,0);
	glEnd();
	glBegin(GL_POLYGON);			//road railing
	glColor4f(0,0,0,1);
		glVertex2i(0,145);
		glVertex2i(0,150);
		glVertex2i(640,150);
		glVertex2i(640,145);
	glEnd();
	glBegin(GL_POLYGON);			//road extension top
	glColor4f(0,1,0,1);
		glVertex2i(0,160);
		glVertex2i(0,200);
		glVertex2i(640,200);
		glVertex2i(640,160);
	glEnd();

	glBegin(GL_POLYGON);			//white line1
	glColor4f(1,1,1,1);
		glVertex2i(7,70);
		glVertex2i(10,80);
		glVertex2i(50,80);
		glVertex2i(47,70);
	glEnd();
	glBegin(GL_POLYGON);			//white line2
	glColor4f(1,1,1,1);
		glVertex2i(97,70);
		glVertex2i(100,80);
		glVertex2i(140,80);
		glVertex2i(137,70);
	glEnd();
	glBegin(GL_POLYGON);			//white line3
	glColor4f(1,1,1,1);
		glVertex2i(187,70);
		glVertex2i(190,80);
		glVertex2i(230,80);
		glVertex2i(227,70);
	glEnd();
	glBegin(GL_POLYGON);			//white line4
	glColor4f(1,1,1,1);
		glVertex2i(277,70);
		glVertex2i(280,80);
		glVertex2i(320,80);
		glVertex2i(317,70);
	glEnd();
	glBegin(GL_POLYGON);			//white line5
	glColor4f(1,1,1,1);
		glVertex2i(367,70);
		glVertex2i(370,80);
		glVertex2i(410,80);
		glVertex2i(407,70);
	glEnd();
	glBegin(GL_POLYGON);			//white line6
	glColor4f(1,1,1,1);
		glVertex2i(457,70);
		glVertex2i(460,80);
		glVertex2i(500,80);
		glVertex2i(497,70);
	glEnd();
	glBegin(GL_POLYGON);			//white line7
	glColor4f(1,1,1,1);
		glVertex2i(547,70);
		glVertex2i(550,80);
		glVertex2i(590,80);
		glVertex2i(587,70);
	glEnd();
	glBegin(GL_POLYGON);			//white line8
	glColor4f(1,1,1,1);
		glVertex2i(637,70);
		glVertex2i(640,80);
		glVertex2i(690,80);
		glVertex2i(687,70);
	glEnd();

	glBegin(GL_POLYGON);			//building
	glColor4f(0.1,0.8,0.8,1);
		glVertex2i(150,155);
		glVertex2i(150,340);
		glVertex2i(350,340);
		glVertex2i(350,155);
	glEnd();
	glBegin(GL_POLYGON);			//building top
	glColor4f(0.1,0.7,0.7,1);
		glVertex2i(150,340);
		glVertex2i(190,360);
		glVertex2i(390,360);
		glVertex2i(350,340);
	glEnd();
	glBegin(GL_LINE_LOOP);			//building top railing
	glColor4f(0,0,0,1);
		glVertex2i(150,340);
		glVertex2i(190,360);
		glVertex2i(390,360);
		glVertex2i(350,340);
	glEnd();
	glBegin(GL_POLYGON);			//building right side
	glColor4f(0.1,0.7,0.7,1);
		glVertex2i(350,340);
		glVertex2i(390,360);
		glVertex2i(390,175);
		glVertex2i(350,155);
	glEnd();
	glBegin(GL_LINE_LOOP);			//top floor
	glColor4f(0,0,0,1);
		glVertex2i(150,315);
		glVertex2i(150,305);
		glVertex2i(350,305);
		glVertex2i(390,325);
		glVertex2i(390,335);
		glVertex2i(350,315);
	glEnd();
	glBegin(GL_LINE_LOOP);			//middle floor
	glColor4f(0,0,0,1);
		glVertex2i(150,280);
		glVertex2i(150,260);
		glVertex2i(350,260);
		glVertex2i(390,280);
		glVertex2i(390,300);
		glVertex2i(350,280);
	glEnd();
	glBegin(GL_LINE_LOOP);			//first floor
	glColor4f(0,0,0,1);
		glVertex2i(150,235);
		glVertex2i(150,225);
		glVertex2i(350,225);
		glVertex2i(390,245);
		glVertex2i(390,255);
		glVertex2i(350,235);
	glEnd();

	glBegin(GL_POLYGON);			//Door
	glColor4f(0,0,0,1);
		glVertex2i(220,156);
		glVertex2i(220,180);
		glVertex2i(290,180);
		glVertex2i(290,156);
	glEnd();

	glBegin(GL_LINE_LOOP);			//tree
	glColor4f(0,0.5,0,1);
		glVertex2i(75,190);
		glVertex2i(80,220);
		glVertex2i(75,220);
		glVertex2i(82,250);
		glVertex2i(90,220);
		glVertex2i(85,220);
		glVertex2i(90,190);
		glVertex2i(75,190);
	glEnd();
	glVertex2i(80,220);
	glVertex2i(75,220);
	glVertex2i(82,250);
	glVertex2i(90,220);
	glVertex2i(85,220);

	glBegin(GL_POLYGON);			//tree bark
	glColor4f(0.2,0,0.03,1);
		glVertex2i(80,190);
		glVertex2i(80,180);
		glVertex2i(85,180);
		glVertex2i(85,190);
	glEnd();

	float j;
  for(j=0;j<640;j+=0.005){
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(30+j,20);
    glVertex2f(30+j,33);
    glVertex2f(48+j,33);
    glVertex2f(48+j,20);
    glEnd();

	}

glFlush();
}

void init(){
    glClearColor(1.0,0.9,0.7,0.0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Multiplex");
    glutDisplayFunc(hello);
    //glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
