#include <stdio.h>

void translate_3D();
void scale_3D();
void shear_3D();

int main() {
    int choice;

    do {
        printf("\n=== 3D Transformations ===\n");
        printf("1. Translation\n");
        printf("2. Scaling\n");
        printf("3. Shearing\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: translate_3D(); break;
            case 2: scale_3D(); break;
            case 3: shear_3D(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void translate_3D() {
    int x, y, z, tx, ty, tz;
    printf("Enter point (x y z): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Enter translation factors (tx ty tz): ");
    scanf("%d %d %d", &tx, &ty, &tz);
    printf("After translation: (%d, %d, %d)\n", x + tx, y + ty, z + tz);
}

void scale_3D() {
    int x, y, z, sx, sy, sz;
    printf("Enter point (x y z): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Enter scaling factors (sx sy sz): ");
    scanf("%d %d %d", &sx, &sy, &sz);
    printf("After scaling: (%d, %d, %d)\n", x * sx, y * sy, z * sz);
}

void shear_3D() {
    int x, y, z, shx, shy, shz;
    printf("Enter point (x y z): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Enter shearing factors (shx shy shz): ");
    scanf("%d %d %d", &shx, &shy, &shz);
    printf("After shearing: (%d, %d, %d)\n", x + shx * y, y + shy * z, z + shz * x);
}
