#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "main.h"

void findMaxOrMin(int* x, int* y, int* z, float* w, char* ch) {
    do {
        puts("Input values for x, y, z:");
        scanf("%d", x);
        PRINTI(*x);
        scanf("%d", y);
        PRINTI(*y);
        scanf("%d", z);
        PRINTI(*z);

        if (*z > 3)
            *w = MIN(SQR(*x + *y), SQR(*x - *z));

        else if (*z <= 3)
            *w = MAX((*x) * (*y) + (*y) * (*z), SQR((*z) * (*x) + (*y) * (*z)));

        PRINTR(*w);

        puts("Repeat? y/n ");
        scanf_s(" %c", ch, 1);

    } while (*ch == 'y');
}
