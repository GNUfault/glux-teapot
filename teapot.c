#include <GL/glut.h>

static float angle = 0.0f;

void initLighting() {
    GLfloat mat_diffuse[]   = {0.8, 0.2, 0.2, 1.0}; 
    GLfloat mat_specular[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_position[] = {0.0, 5.0, 10.0, 1.0}; 

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle, 0.0, 1.0, 0.0);   
    glutSolidTeapot(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void idle() {
    angle += 0.5f;                     
    if (angle > 360.0f) angle -= 360.0f;
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 5.0,   
              0.0, 0.0, 0.0,   
              0.0, 1.0, 0.0);  
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Classic IRIX Teapot");

    initLighting();
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
