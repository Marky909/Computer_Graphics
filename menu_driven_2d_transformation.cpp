#include <stdio.h>
#include <graphics.h>
#include <math.h>

void translate_2D();
void scale_2D();
void rotate_2D();
void shear_2D();
void reflect_2D();

int main() {
    int choice;

    do {
        printf("\n=== 2D Transformations ===\n");
        printf("1. Translation\n");
        printf("2. Scaling\n");
        printf("3. Rotation\n");
        printf("4. Shearing\n");
        printf("5. Reflection\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: translate_2D(); break;
            case 2: scale_2D(); break;
            case 3: rotate_2D(); break;
            case 4: shear_2D(); break;
            case 5: reflect_2D(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void translate_2D() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, tx, ty;
    initgraph(&gd, &gm, (char*)"");

    printf("Enter rectangle coordinates (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("Enter translation factors (tx ty): ");
    scanf("%d %d", &tx, &ty);

    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Object");

    setcolor(WHITE);
    rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
    outtextxy(x1 + tx, y1 + ty - 10, "Image");

    getch();
    closegraph();
}

void scale_2D() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, sx, sy;
    initgraph(&gd, &gm, (char*)"");

    printf("Enter rectangle coordinates (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("Enter scaling factors (sx sy): ");
    scanf("%d %d", &sx, &sy);

    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Object");

    setcolor(WHITE);
    rectangle(x1 * sx, y1 * sy, x2 * sx, y2 * sy);
    outtextxy(x1 * sx, y1 * sy - 10, "Image");

    getch();
    closegraph();
}

void rotate_2D() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float angle, rad, xr1, yr1, xr2, yr2;
    initgraph(&gd, &gm, (char*)"");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("Enter rotation angle (degrees): ");
    scanf("%f", &angle);

    rad = angle * (3.14 / 180);
    xr1 = x1 * cos(rad) - y1 * sin(rad);
    yr1 = x1 * sin(rad) + y1 * cos(rad);
    xr2 = x2 * cos(rad) - y2 * sin(rad);
    yr2 = x2 * sin(rad) + y2 * cos(rad);

    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Object");

    setcolor(WHITE);
    line(xr1, yr1, xr2, yr2);
    outtextxy(xr1, yr1 - 10, "Image");

    getch();
    closegraph();
}

void shear_2D() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, shx, shy;
    initgraph(&gd, &gm, (char*)"");

    printf("Enter rectangle coordinates (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("Enter shearing factors (shx shy): ");
    scanf("%d %d", &shx, &shy);

    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Object");

    setcolor(WHITE);
    rectangle(x1 + shx * y1, y1 + shy * x1, x2 + shx * y2, y2 + shy * x2);
    outtextxy(x1 + shx * y1, y1 + shy * x1 - 10, "Image");

    getch();
    closegraph();
}

void reflect_2D() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    initgraph(&gd, &gm, (char*)"");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Object");

    setcolor(WHITE);
    line(x1, getmaxy() - y1, x2, getmaxy() - y2);
    outtextxy(x1, getmaxy() - y1 - 10, "Image");

    getch();
    closegraph();
}
