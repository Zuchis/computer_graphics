#include <GL/freeglut.h>

static void renderBlack()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Black Screen yay :D");
    glutDisplayFunc(renderBlack);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glutMainLoop();
    
    return 0;
}
