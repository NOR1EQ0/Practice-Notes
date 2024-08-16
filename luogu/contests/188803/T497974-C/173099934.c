#include <stdio.h>

int main() {
    int n, a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int buf = 0;
        scanf("%d", &buf);
        a += buf;
    }
    for (int i = 0; i < n; ++i) {
        int buf = 0;
        scanf("%d", &buf);
        b += buf;
    }
    n = (a + b + 1) / 2;
    printf("%d", n);
    return 0;
}