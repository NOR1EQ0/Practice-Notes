#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, a;
        scanf("%d", &n);
        if (n == 2)
        {
            scanf("%d %d", &a, &n);
            if (a - n == 1 || a - n == -1) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a);
            }
            printf("NO\n");
        }
    }
    return 0;
}