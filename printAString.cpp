#include<iostream>
#include<fstream>
#include<GL/gl.h>
#include<GL/glut.h>

using namespace std;
void introscreen();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Character Print.");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

void init(){
    glClearColor(0.8,1,1,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);
}

void display(){
  introscreen();
  glFlush();
    glutPostRedisplay();
}

void introscreen(){
  glColor3f(1.f,1.f,1.f);
  char buf[100]={0};
  sprintf_s(buf,"Doofenshmirtz Evil Inc.");
  renderBitmap(-80,40,GLUT_BITMAP_TIMES_ROMAN_24, buf);
  //sprintf_s(buf,"Doofenshmirtz Evil Inc.");
  //renderBitmap(-80,35,GLUT_BITMAP_TIMES_ROMAN_18,buf);
}

void renderBitmap(float x, float y, void *font, char *string){
  char *c;
  glRasterPos2f(x,y);
  for (c=string; *c!='\0'; c++){
    glutBitmapCharacter(font,*c);
  }
}
