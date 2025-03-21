#include <stdio.h>

int main() {
    while (getchar() != ' ');
    while (1) {
        char a = getchar();
        if (a != ' ')
            putchar(a);
        else
            return 0;
    }
    return 0;
}