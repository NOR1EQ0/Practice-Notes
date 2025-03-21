#include <stdio.h>

int main() {
    float h, r;
    scanf("%f %f", &h, &r);
    float v = r * r * h * 3.14;
    printf("%d\n", (int)((20000 + v) / v));
    return 0;
}