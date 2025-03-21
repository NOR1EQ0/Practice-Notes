#include <stdio.h>
#include <stdbool.h>
#define ull unsigned long long

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        ull x, y, ans = 0;
        scanf("%llu%llu", &x, &y);
        int _0to1 = -1; // -1 uninit
        while (x || y) {
            bool flag = x % 2;
            if (!(x % 2 ^ y & 2)) {
                if (x % 2) _0to1 = 0;
                else _0to1 = 1;
                if (_0to1 ^ flag) {
                    ans++;
                }
            }
            x >>= 1;
            y >>= 1;
        }
        printf("%llu\n", ans);
    }
    return 0;
}
