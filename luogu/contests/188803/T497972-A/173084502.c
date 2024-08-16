#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, n;
    scanf("%d %d", &x, &y);
    x -= 2000;
    n = (x-1) * 12 + y;
    printf("%d", n - (15 * 12 + 8) + 1);
    return 0;
}