#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int boundry[4][3] = {{50, 50, 50}, {500, 50, 50}, {50, 500, 50}, {500, 500, 50}};
    int rect1[4][3] = {{80, 80, 40}, {80, 100, 40}, {300, 80, 40}, {300, 300, 40}};
    int rect2[4][3] = {{200, 70, 30}, {400, 70, 30}, {200, 200, 30}, {400, 400, 30}};

    rectangle(boundry[0][0], boundry[0][1], boundry[3][0], boundry[3][1]);
    rectangle(rect1[0][0], rect1[0][1], rect1[3][0], rect1[3][1]);
    rectangle(rect2[0][0], rect2[0][1], rect2[3][0], rect2[3][1]);

    int a = boundry[0][2];
    int b = rect1[0][2];
    int c = rect2[0][2];
    int depth[3];
    int p, q, r;

    if (a < c) {
        p = b;
        depth[0] = a;
    } else {
        q = b;
        depth[0] = c;
    }

    if (p < q) {
        r = q;
        depth[1] = p;
        depth[2] = r;
    } else {
        r = p;
        depth[1] = q;
        depth[2] = r;
    }

    for (int j = 0; j < 3; j++) {
        printf("\t%d", depth[j]);
    }

    if (depth[2] == a) {
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        bar(boundry[0][0], boundry[0][1], boundry[3][0], boundry[3][1]);
    } else if (depth[2] == b) {
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        bar(rect1[0][0], rect1[0][1], rect1[3][0], rect1[3][1]);
    } else if (depth[2] == c) {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        bar(rect2[0][0], rect2[0][1], rect2[3][0], rect2[3][1]);
    }

    getchar();
    closegraph();
    return 0;
}

