#include <stdio.h>
#define bool _Bool

int main() {
    int n, x, ans = 0;
    scanf("%d%d", &n, &x);
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        int in;
        scanf("%d", &in);
        if (in <= x) {
            ans++;
        } else {
            if (flag == 1) {
                break;
            }
            flag = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}