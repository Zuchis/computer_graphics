#include <cstdlib>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>

typedef struct {
    int width;
    int height;
    char* title;

    float field_of_view_angle;
    float z_near;
    float z_far;
} glutWindow;

float zoera = 0.0;

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.9f, 2.0f, 3.0f);

    gluLookAt(4.5, 10.0, 7.2,
            0.0, 0.0, 0.0,
            0.0, 0.0, 1.0);

    zoera += 12.0;

    glRotated(zoera, 0, 0, 1);

    glPushMatrix();
            glTranslatef(0.0, 0.0, 0.75);
            glColor3f(1.0, 1.0, 1.0);
            glPushMatrix();
                    glTranslatef(0.0, 0.0, 0.75);
                    glutSolidSphere(0.75, 20, 20);
            glPopMatrix();
        glPushMatrix();
                glTranslatef(0.0, 0.0, 1.75); 
                glutSolidSphere(0.25, 20, 20); 

                glColor3f(0.0, 0.0, 0.0);
                glPushMatrix();
                        glTranslatef(0.0, -0.18, 0.10); 
                        glPushMatrix();
                                glTranslatef(-0.05, 0.0, 0.0);
                                glutSolidSphere(0.05, 10, 10);
                        glPopMatrix();
                        glPushMatrix();
                                glTranslatef(+0.05, 0.0, 0.0);
                                glutSolidSphere(0.05, 10, 10);
                        glPopMatrix();
                glPopMatrix();


                glColor3f(1.0, 0.5, 0.5); 
                glPushMatrix();
                        glRotatef(90.0, 1.0, 0.0, 0.0); 
                        glutSolidCone(0.08, 0.5, 10, 2); 
                glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

int main (int argc, char **argv)
{
    glutWindow win;

    win.width  = 800;
    win.height = 600;
    win.z_near = 2.0f;
    win.z_far  = 15.0f;
    win.title = "Bonecoas de Nevoas Boladoas de Chernobyoas";
    win.field_of_view_angle = 45;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(win.width,win.height);
    glutCreateWindow(win.title);

    glutDisplayFunc(display);
    glutIdleFunc( display );

    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, win.width, win.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat aspect = (GLfloat) win.width / win.height;
    gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
    glClearColor(0.0, 0.0, 0.0, 1.0);

    GLfloat mat_shininess[] =  { 50.0 };
    GLfloat mat_specular[] =   { 0.75, 0.75, 0.75, 0.75 };

    GLfloat light_ambient[] =  {  0.0,  1.0,  0.0, 1.0 };
    GLfloat light_diffuse[] =  {  1.0,  1.0,  1.0, 1.0 };
    GLfloat light_specular[] = {  1.0,  1.0,  1.0, 1.0 };
    GLfloat light_position[] = {  10.0,  2.0,  10.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glutMainLoop();

    return 0;
}
