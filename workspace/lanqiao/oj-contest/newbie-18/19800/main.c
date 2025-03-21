#include <stdio.h>

int main() {
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n - k; ++i) {
        if (n % i == k) {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}