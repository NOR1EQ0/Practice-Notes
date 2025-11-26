#include <stdio.h>

int main() {
    long a, b, c;
    scanf("%ld%ld%ld", &a, &b, &c);
    printf("%ld\n%ld\n", 2 * (a * b + b * c + a * c), a * b * c);
}