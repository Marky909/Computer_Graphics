#include <graphics.h>
#include <stdio.h>
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

int computeCode(int x, int y) {
    int code = 0;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) { // Both endpoints inside
            accept = 1;
            break;
        } else if (code1 & code2) { // Both endpoints share an outside region
            break;
        } else { // Line is partially inside
            int code_out, x, y;
            code_out = code1 ? code1 : code2;
            
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept) {
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(RED);
    line(50, 50, 350, 350);
    delay(2000);
    setcolor(GREEN);
    cohenSutherlandClip(50, 50, 350, 350);
    
    getchar();
    closegraph();
    return 0;
}
