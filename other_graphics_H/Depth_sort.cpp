#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int boundry[4][3] = {{50, 50, 50}, {500, 50, 50}, {50, 500, 50}, {500, 500, 50}};
    int rect1[4][3] = {{80, 80, 40}, {80, 300, 40}, {300, 80, 40}, {300, 300, 40}};
    int rect2[4][3] = {{200, 70, 30}, {200, 200, 30}, {400, 70, 30}, {400, 400, 30}};

    // Draw boundary in white
    setcolor(WHITE);
    rectangle(boundry[0][0], boundry[0][1], boundry[3][0], boundry[3][1]);

    // Initialize depths
    int depth[3] = {boundry[0][2], rect1[0][2], rect2[0][2]};

    // Sorting depths in decreasing order (Bubble Sort)
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (depth[i] < depth[j]) {
                int temp = depth[i];
                depth[i] = depth[j];
                depth[j] = temp;
            }
        }
    }

    // Filling topmost (visible) surface first using correct patterns
    for (int j = 0; j < 3; j++) {
        if (depth[j] == boundry[0][2]) {
            setfillstyle(HATCH_FILL, WHITE); // Hatch fill
            bar(boundry[0][0], boundry[0][1], boundry[3][0], boundry[3][1]);
        } else if (depth[j] == rect1[0][2]) {
            setfillstyle(LINE_FILL, WHITE); // Horizontal lines
            bar(rect1[0][0], rect1[0][1], rect1[3][0], rect1[3][1]);
        } else if (depth[j] == rect2[0][2]) {
            setfillstyle(SLASH_FILL, WHITE); // Left-slash fill
            bar(rect2[0][0], rect2[0][1], rect2[3][0], rect2[3][1]);
        }
    }

    delay(2000); // Hold window for visualization
    getchar();
    closegraph();
    return 0;
}
