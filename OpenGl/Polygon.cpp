#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(0, 0.8);
    glVertex2f(-0.7, 0.3);
    glVertex2f(-0.5, -0.6);
    glVertex2f(0.5, -0.6);
    glVertex2f(0.7, 0.3);
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
