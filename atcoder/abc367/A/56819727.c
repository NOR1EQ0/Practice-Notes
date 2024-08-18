#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (b < c) {
        if (a >= b && a < c) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    } else {
        if (a >= b || a < c) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}