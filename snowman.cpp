#include <cstdlib>
#include <GL/freeglut.h>

static void drawDaSnowman()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //main
    glPushMatrix();
            glTranslatef(0.0, 0.0, 0.75);
            glColor3f(1.0, 1.0, 1.0);
            glPushMatrix();
                    glTranslatef(0.0, 0.0, 0.75);
                    glutSolidSphere(0.75, 20, 20);
            glPopMatrix();
        //head
        glPushMatrix();
                glTranslatef(0.0, 0.0, 1.75); 
                glutSolidSphere(0.25, 20, 20); 

                // Eyes 
                glColor3f(0.0, 0.0, 0.0);
                glPushMatrix();
                        glTranslatef(0.0, -0.18, 0.10); 
                        glPushMatrix();
                                glTranslatef(-0.05, 0.0, 0.0);
                                glutSolidSphere(0.05, 10, 10); // right eye
                        glPopMatrix();
                        glPushMatrix();
                                glTranslatef(+0.05, 0.0, 0.0);
                                glutSolidSphere(0.05, 10, 10); // left eye
                        glPopMatrix();
                glPopMatrix();

                // Nose 
                glColor3f(1.0, 0.5, 0.5); 
                glPushMatrix();
                        glRotatef(90.0, 1.0, 0.0, 0.0); 
                        glutSolidCone(0.08, 0.5, 10, 2); 
                glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Snowman Bolado");
    glutDisplayFunc(drawDaSnowman);
    //glClearColor(0.0f,0.0f,0.0f,0.0f);
    glutMainLoop();
    
    return 0;
}
