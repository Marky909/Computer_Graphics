#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>


void sun(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    int i;
    for ( i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


void init(void)
{
    glClearColor(0.0, 0.9, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
float bx = 50;
float ax = 10;
void clouds()
{
    glPushMatrix();
    glTranslatef(bx, 0, 0);
    // 1st cloud
    glColor3ub(255, 255, 255);


    sun(20, 30, 460, 460);


    sun(15, 20, 445, 460);


    sun(15, 20, 475, 460);


    // 2nd cloud


    sun(20, 30, 390, 420);


    sun(15, 20, 405, 420);


    sun(15, 20, 375, 420);


    glPopMatrix();
    ax += .05;
    if (ax > 0)
        ax = -500;
    glutPostRedisplay();


}
void boat() {


    glPushMatrix();
    glTranslatef(bx, 0, 0);


    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(325, 220);
    glVertex2d(400, 220);
    glVertex2d(425, 250);
    glVertex2d(300, 250);
    glEnd();


    glColor3ub(205, 133, 63);
    glBegin(GL_POLYGON);
    glVertex2d(325, 250);
    glVertex2d(400, 250);
    glVertex2d(390, 280);
    glVertex2d(335, 280);
    glEnd();


    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(360, 280);
    glVertex2d(370, 280);
    glVertex2d(370, 310);
    glVertex2d(360, 310);
    glEnd();


    glColor3ub(128,0,128);
    glBegin(GL_POLYGON);
    glVertex2d(335, 290);
    glVertex2d(390, 290);
    glVertex2d(390, 375);
    glVertex2d(335, 375);
    glEnd();


    glPopMatrix();


    bx += .13;
    if (bx > 0)
        bx = -550;
    glutPostRedisplay();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    //Ground Color
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 300);
    glVertex2d(0, 300);
    glEnd();


    // River


    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(250, 150);
    glVertex2d(400, 150);
    glVertex2d(450, 300);
    glEnd();


    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(300, 150);
    glVertex2d(250, 0);
    glVertex2d(400, 0);
    glVertex2d(450, 150);
    glEnd();


    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 200);
    glVertex2d(0, 300);
    glVertex2d(500, 300);
    glVertex2d(500, 200);
    glEnd();




    // Hills 1
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 300);
    glVertex2d(200, 300);
    glVertex2d(100, 450);
    glEnd();


    // Hills 2
    glColor3ub(218, 165, 32);
    glBegin(GL_POLYGON);
    glVertex2d(150, 300);
    glVertex2d(350, 300);
    glVertex2d(250, 450);
    glEnd();


    // Hills 3
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(520, 300);
    glVertex2d(400, 450);
    glEnd();


    // Boat design function call
    boat();
    // House Tree


    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(50, 150);
    glVertex2d(70, 150);
    glVertex2d(70, 300);
    glVertex2d(50, 300);
    glEnd();


    // Tree leaf


    glColor3ub(0, 128, 0);
    sun(30, 40, 35, 320);


    glColor3ub(0, 128, 0);
    sun(30, 40, 85, 320);


    glColor3ub(0, 128, 0);
    sun(25, 30, 45, 370);


    glColor3ub(0, 128, 0);
    sun(30, 30, 70, 370);


    glColor3ub(0, 128, 0);
    sun(25, 30, 55, 400);


    // 2nd House


    glColor3ub(210, 105, 30);
    glBegin(GL_POLYGON);
    glVertex2d(100, 220);
    glVertex2d(200, 220);
    glVertex2d(175, 270);
    glVertex2d(130, 270);
    glEnd();


    glColor3ub(244, 164, 96);
    glBegin(GL_POLYGON);
    glVertex2d(100, 170);
    glVertex2d(185, 170);
    glVertex2d(185, 220);
    glVertex2d(100, 220);
    glEnd();


    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(100, 170);
    glVertex2d(190, 170);
    glVertex2d(190, 160);
    glVertex2d(100, 160);
    glEnd();


    // 2nd house door and window


    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(140, 170);
    glVertex2d(165, 170);
    glVertex2d(165, 200);
    glVertex2d(140, 200);
    glEnd();




    // 1st House


    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(0, 220);
    glVertex2d(135, 220);
    glVertex2d(110, 270);
    glVertex2d(25, 270);
    glEnd();


    glColor3ub(255, 222, 173);
    glBegin(GL_POLYGON);
    glVertex2d(10, 220);
    glVertex2d(50, 220);
    glVertex2d(25, 255);
    glEnd();


    glColor3ub(255, 222, 173);
    glBegin(GL_POLYGON);
    glVertex2d(10, 150);
    glVertex2d(50, 150);
    glVertex2d(50, 220);
    glVertex2d(10, 220);
    glEnd();


    glColor3ub(222, 184, 135);
    glBegin(GL_POLYGON);
    glVertex2d(50, 150);
    glVertex2d(125, 150);
    glVertex2d(125, 220);
    glVertex2d(50, 220);
    glEnd();


    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(10, 150);
    glVertex2d(125, 150);
    glVertex2d(125, 140);
    glVertex2d(10, 140);
    glEnd();


    // 1st house door and window


    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(75, 150);
    glVertex2d(95, 150);
    glVertex2d(95, 195);
    glVertex2d(75, 195);
    glEnd();


    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(20, 200);
    glVertex2d(35, 200);
    glVertex2d(35, 175);
    glVertex2d(20, 175);
    glEnd();


    //sun design
    glColor3ub(255, 215, 0);
    sun(25, 30, 175, 450);


    // counds function
    clouds();


    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Village Scenery");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

