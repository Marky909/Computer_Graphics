#include <GL/glut.h>
#include <math.h>

GLfloat angle = 0; // Rotation angle

void drawCube()
{
    GLfloat vertices[][3] = {{-1, -1, -1}, {-1, -1, 1}, {-1, 1, -1}, {-1, 1, 1},
                             {1, -1, -1}, {1, -1, 1}, {1, 1, -1}, {1, 1, 1}};
    GLint faces[][4] = {{0, 1, 3, 2}, {4, 5, 7, 6}, {0, 2, 6, 4},
                        {1, 3, 7, 5}, {2, 3, 7, 6}, {0, 1, 5, 4}};
    GLfloat colors[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                           {1, 1, 0}, {1, 0, 1}, {0, 1, 1}};

    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++)
    {
        glColor3fv(colors[i]);
        for (int j = 0; j < 4; j++)
            glVertex3fv(vertices[faces[i][j]]);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 1, 1, 1);
    drawCube();
    glutSwapBuffers();
}

void timer(int)
{
    angle += 1.0;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 1, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Cube");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, timer, 0);
    glutMainLoop();
}
