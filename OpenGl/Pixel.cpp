#include <GL/glut.h>

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1); // Blue pixels
    glPointSize(8);     // Bigger pixels for visibility

    drawPixel(250, 250); // Center pixel
    drawPixel(100, 100); // Bottom-left
    drawPixel(400, 400); // Top-right
    drawPixel(100, 400); // Top-left
    drawPixel(400, 100); // Bottom-right

    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1); // White background
    gluOrtho2D(0, 500, 0, 500); // Window coordinate system
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bigger Pixels");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
