#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int l = a - b, r = a + b;
    if (l > -1) printf("%d ", l);
    if (r < n + 1 && r != l) printf("%d ", r);
    if (l < 0 && r > n) puts("No solution");
    putchar('\n');
    return 0;
}
