#include <graphics.h>
#include <stdio.h>

void floodFill(int x, int y, int oldColor, int newColor) {
    int currentColor = getpixel(x, y);
    if (currentColor == oldColor) {
        putpixel(x, y, newColor);
        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(150, 150, 250, 250);
    int x = 200, y = 200;
    int oldColor = getpixel(x, y);
    int newColor = YELLOW;

    floodFill(x, y, oldColor, newColor);

    getch();
    closegraph();
}

