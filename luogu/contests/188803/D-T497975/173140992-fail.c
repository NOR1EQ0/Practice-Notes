#include <stdio.h>

int main() {
    int n, m, a, b, ans = 0;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < m; ++i) {
        // Start
        int l, flag = 0, j = 0;
        scanf("%d", &l);
        for (; i < l; ++j) {
            scanf("%d", &n);
            if (n == a) {
                flag = 1;
                j++;
                break;
            } else if (n == b) {
                flag = 2;
                j++;
                break;
            }
        }
        if (flag == 1) {
            for (;j < l; ++j) {
                scanf("%d", &n);
                if (n == b) {
                    ans++;
                    j++;
                    break;
                }
            }
        }
        for (;j < l; ++j) {
            scanf("%d", &n);
        }
        // End
    }
    printf("%d", ans);
    return 0;
}