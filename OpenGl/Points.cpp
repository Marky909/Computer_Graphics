#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0); // Red points
    glPointSize(10);    // Bigger points for visibility

    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);   // Center point
    glVertex2f(-0.5, -0.5); // Bottom-left
    glVertex2f(0.5, 0.5);   // Top-right
    glVertex2f(0.S5, -0.5);  // Bottom-right
    glVertex2f(-0.5, 0.5);  // Top-left
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1); // White background
    gluOrtho2D(-1, 1, -1, 1); // 2D coordinate system
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bigger Points");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
