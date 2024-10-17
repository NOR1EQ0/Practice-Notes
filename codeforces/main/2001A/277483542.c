#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d", &n);
            printf("0\n");
            continue;
        }
        int a[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int max = 0;
        int modebuf[n];
        memset(modebuf, 0, sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            modebuf[a[i] - 1]++;
        }
        for (int i = 0; i < n; ++i) {
            if (modebuf[i] > max) {
                max = modebuf[i];
            }
        }
        printf("%d\n", n - max);
    }
}