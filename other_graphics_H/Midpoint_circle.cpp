#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void plotPoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, YELLOW);
    putpixel(xc - x, yc + y, YELLOW);
    putpixel(xc + x, yc - y, YELLOW);
    putpixel(xc - x, yc - y, YELLOW);
    putpixel(xc + y, yc + x, YELLOW);
    putpixel(xc - y, yc + x, YELLOW);
    putpixel(xc + y, yc - x, YELLOW);
    putpixel(xc - y, yc - x, YELLOW);
}
int  main() {
    int gd = DETECT, gm;
    int xc, yc, r, x, y, p;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the center (x y) and radius: ");
    scanf("%d%d%d", &xc, &yc, &r);

    x = 0;
    y = r;
    p = 1 - r;

    plotPoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * x + 1 - 2 * y;
        }
        plotPoints(xc, yc, x, y);
        delay(10);
    }

    getch();
    closegraph();
}
