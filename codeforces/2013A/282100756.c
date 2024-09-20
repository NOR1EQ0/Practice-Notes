#include <stdio.h>

int min(int x, int y) {
    if (x > y)
        return y;
    return x;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        printf("%d\n", (n + min(x, y) - 1) / min(x, y));
    }
    return 0;
}