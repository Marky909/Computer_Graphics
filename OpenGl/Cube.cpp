#include <GL/glut.h>
#include <math.h>

#define NUM_VERTICES 8
#define NUM_FACES 6

GLint vertices[NUM_VERTICES][3] = {
    {0, 0, 0}, {0, 0, 2}, {0, 2, 0}, {0, 2, 2}, {2, 0, 0}, {2, 0, 2}, {2, 2, 0}, {2, 2, 2}};

GLint faces[NUM_FACES][4] = {
    {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6}, {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};

GLfloat vertexColors[NUM_VERTICES][3] = {
    {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}};

void drawCube()
{
    glBegin(GL_QUADS);
    for (int i = 0; i < NUM_FACES; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            glColor3fv(vertexColors[faces[i][j]]);
            glVertex3iv(vertices[faces[i][j]]);
        }
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawCube();
    glFlush();
    glutSwapBuffers();
}

void timer(int v)
{
    static GLfloat u = 0.0;
    u += 0.01;
    glLoadIdentity();
    gluLookAt(10 * cos(u), 9 * cos(u) - 1, 6 * cos(u / 3) + 2, 1, 1, 1, cos(u), 1, 0);
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.5, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bigger RGB Color Cube");
    glutReshapeFunc(reshape);
    glutTimerFunc(100, timer, 0);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}