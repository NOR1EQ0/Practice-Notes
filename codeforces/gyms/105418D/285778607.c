#include <stdio.h>

typedef unsigned long long i64;
int main(int argc, char const* argv[]) {
    int t, ans = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        i64 d;
        scanf("%llu", &d);
        printf("%llu\n", (d - 1) * d / 2);
    }
    return 0;
}
