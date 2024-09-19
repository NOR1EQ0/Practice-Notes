#include <stdio.h>

int main() {
    char str[25];
    char str2[24];
    for (char* ptr = str, i = 0; i < 25; ptr++, i++) {
        *ptr = getchar();
    }
    return 0;
}