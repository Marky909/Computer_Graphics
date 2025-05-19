#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    float x1, y1, x2, y2, dx, dy, steps, x, y;
    int i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the coordinates (x1 y1): ");
    scanf("%f%f", &x1, &y1);
    printf("Enter the coordinates (x2 y2): ");
    scanf("%f%f", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    dx = dx / steps;
    dy = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), RED);
        x += dx;
        y += dy;
        delay(10);
    }

    getch();
    closegraph();
}

