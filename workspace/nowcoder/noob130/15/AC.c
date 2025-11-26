#include <stdio.h>

int main() {
    char c;
    long s = 0;
    while ((c = getchar()) != EOF || c != '\n') {
        s += (c - '0');
    }
    printf("%ld", s);
}