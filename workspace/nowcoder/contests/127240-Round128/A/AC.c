#include <stdio.h>

int main() {
    getchar();
    char c = getchar();
    if (getchar() == c) {
        puts("Yes");
    } else {
        puts("No");
    }
}