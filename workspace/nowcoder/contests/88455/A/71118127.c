#include <stdio.h>
#define i64 long long

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        i64 a, b, x, y;
        scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
        i64 color = y * b;
        i64 both = 0;
        if (x < y) {
            both = x * a;
        } else {
            both = y * a;
        }
        printf("%lld\n", color + both);
    }
    return 0;
}