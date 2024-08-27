#include <stdio.h>

int main() {
    int w;
    scanf("%d", &w);
    (w % 2 || w < 3) ? printf("NO\n") : printf("YES\n");
    return 0;
}