#include <stdio.h>

int main() {
    float t;
    int n;
    scanf("%f %d", &t, &n);
    printf("%.3f\n%d\n", t / n, 2 * n);
    return 0;
}