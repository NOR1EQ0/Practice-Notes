#include <stdio.h>
#define plz puts("lz")
#define pgzy puts("gzy")

int main() {
    int a1, b1, a2, b2;
    scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
    if (a2 * b2 <= a1 * b1) {
        pgzy;
    } else {
        plz;
    }
    return 0;
}