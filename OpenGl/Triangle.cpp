#include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Centering the triangle
}

void triangle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES); // Properly defining a triangle
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex2f(-0.5, -0.5);

        glColor3f(0.0, 1.0, 0.0); // Green
        glVertex2f(0.5, -0.5);

        glColor3f(0.0, 0.0, 1.0); // Blue
        glVertex2f(0.0, 0.5);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Colorful Triangle");

    init();
    glutDisplayFunc(triangle);
    glutMainLoop();

    return 0;
}
