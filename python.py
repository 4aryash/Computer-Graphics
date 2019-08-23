import  OpenGL.GL
import  OpenGL.GLUT
import  OpenGL.GLU

def hello():
	glClear(GL_COLOR_BUFFER_BIT)
	glClearColor(1.0, 0.0, 0.0,0.0)
	glColor4f(1,0,0,1)
	glBegin(GL_POLYGON )
	glVertex2i(100,100)
	glVertex2i(-100,100)
	glVertex2i(100,-100)
	glEnd()
	glFlush()


def init():
    glClearColor(1.0,1.0,1.0,0.0)
    #glMatrixMode(GL_PROJECTION)
    gluOrtho2D(0,640,0,480)

def main():
    glutInit()
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB)
    glutInitWindowSize(1000,600)
    glutInitWindowPosition(200,200)
    glutCreateWindow("Triangle banane ki koshish.")
    glutDisplayFunc(hello)
    #glutMouseFunc(mouse)
    init()
    glutMainLoop()
    return


if __name__ == "__main__":
	main()
