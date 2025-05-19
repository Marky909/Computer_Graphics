#include <graphics.h>
#include <stdio.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int current = getpixel(x, y);
    if (current != boundaryColor && current != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(100, 100, 200, 200);
    boundaryFill(150, 150, GREEN, WHITE);

    getch();
    closegraph();
}

