#include <stdio.h>

int main() {
    int t = 0;
    char in;
    for (int i = 1; i < 13; ++i) {
        int a = 0;
        while ((in = getchar()) != '\n') {
            a++;
        }
        if (a == i) t++;
    }
    printf("%d", t);
    return 0;
}