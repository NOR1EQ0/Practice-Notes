#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define i64 long long

int main() {
    int n;
    scanf("%d", &n);
    long double ans = 0;
    i64 a = 0, b = 0; // current
    for (int i = 0; i < n; ++i) {
        i64 x, y;
        scanf("%lld%lld", &x, &y);
        ans += sqrtl((a - x) * (a - x) + (b - y) * (b - y));
        a = x, b = y;
    }
    ans += sqrtl(a*a + b*b);
    printf("%Lf", ans);
    return 0;
}