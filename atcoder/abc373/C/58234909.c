#include <stdio.h>
#define int long long

signed main() {
    int t, a, b, tmp;
    scanf("%lld%lld%lld", &t, &a, &b);
    for (int i = 1; i < t; ++i) {
        scanf("%lld", &tmp);
        if (tmp > a) {
            a = tmp;
        }
    }
    for (int i = 1; i < t; ++i) {
        scanf("%lld", &tmp);
        if (tmp > b) {
            b = tmp;
        }
    }
    printf("%lld\n", a + b);
    return 0;
}