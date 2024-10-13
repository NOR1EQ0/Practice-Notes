#include <stdio.h>

typedef long long i64;
int main(int argc, char const* argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        i64 d, ans = 0;
        scanf("%lld", &d);
        for (i64 j = 0; j < d; j++) {
            ans += j;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
