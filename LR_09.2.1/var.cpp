#include <stdio.h>
#define Z 3
#define SQR(x) ((x) * (x))
#define MAX(y, z) (((y) > (z)) ? (y) : (z))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define PRINTI(w) puts("control output"); printf(#w "=%d\n", w)
#define PRINTR(w) puts("result:"); printf(#w "=%f\n", (float)w)

int main() {
    int x, y;
    float w;
    char ch;

    do {
        puts("Input values for x and y:");
        scanf("%d", &x);
        PRINTI(x);
        scanf("%d", &y);
        PRINTI(y);

#if Z > 3
        w = MIN(SQR(x + y), SQR(x - Z));
#elif Z <= 3
        w = MAX(x * (y + y) * Z, SQR(Z * x) + y * Z);
#endif

        PRINTR(w);

        puts("Repeat? y/n ");
        scanf(" %c", &ch);
    } while (ch == 'y');

    return 0;
}
