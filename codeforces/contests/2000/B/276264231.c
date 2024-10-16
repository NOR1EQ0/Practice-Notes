#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, l, r, j, a;
        scanf("%d", &n);
        scanf("%d", &a);
        l = a - 1;
        r = a + 1;
        for (j = 1; j < n; j++) {
            scanf("%d", &a);
            if (a == l) {
                l--;
                continue;
            }
            if (a == r) {
                r++;
                continue;
            }
            j++;
            break;
        }
        if (j < n) {
            for (; j < n; j++) {
                scanf("%d", &a);
            }
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}