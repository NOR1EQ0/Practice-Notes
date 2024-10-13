#include <stdio.h>

int main(int argc, char const *argv[])
{
    char in[2];
    in[0] = getchar();
    in[1] = getchar();
    if (in[0] != in[1]) {
        printf("No\n");
        return 0;
    }
    in[1] = getchar();
    if (in[1] == EOF || in[1] == '\n') {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    return 0;
}
