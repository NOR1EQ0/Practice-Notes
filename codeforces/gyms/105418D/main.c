#include <stdio.h>

typedef unsigned long long i64;
int main(int argc, char const* argv[]) {
    i64 d = (unsigned)1e9, ans = 0;
    for (i64 j = 0; j < d; j++) {
        ans += j;
    }
    printf("%llu\n", ans);
    return 0;
}
