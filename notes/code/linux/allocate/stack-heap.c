#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    printf("%p\n", &a);
    printf("%p\n", malloc(sizeof(int)));
}