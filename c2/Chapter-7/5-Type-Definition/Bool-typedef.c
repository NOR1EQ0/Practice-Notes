#include <stdio.h>
#include <stdlib.h>

typedef int Bool;

int main(int argc, char const *argv[])
{
    Bool b1 = 2;
    int i1 = 5;
    printf("Bool b1: %d\nint i1: %d\n", b1, i1);
    printf("sizeof(b1): %ld\nsizeof(i1): %ld\n", sizeof(b1), sizeof(i1));
    return 0;
}
