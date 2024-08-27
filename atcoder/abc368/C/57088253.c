#include <stdio.h>
#define i64 long long

int main() {
    i64 n, t = 0, rest = 0;
    i64 a;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &a);
        if (rest == 1) {
            a--;
            rest = 2;
            t++;
        }
        if (a <= 0) {
            continue;
        }
        if (rest == 2) {
            a -= 3;
            rest = 0;
            t++;
        }
        if (a <= 0) {
            continue;
        }

        rest = a % 5;
        t += a / 5 * 3;
        if (rest > 2) {
            rest = 0;
            t += 3;
            continue;
        }
        t += rest;
    }
    printf("%lld\n", t);
    return 0;
}