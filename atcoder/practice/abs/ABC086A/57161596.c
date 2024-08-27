#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a % 2 && b % 2) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }
    return 0;
}