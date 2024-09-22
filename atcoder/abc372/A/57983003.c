#include <stdio.h>

int main() {
    char in = 1;
    while (in) {
        in = getchar();
        if (in == '\n') {
            return 0;
        }
        if (in != '.') {
            putchar(in);
        }
    }
    return 0;
}