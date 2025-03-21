#include <stdio.h>
#include <stdbool.h>


int main() {
    int t;
    scanf("%d", &t);
    for (int a = 0; a < t; ++a) {
        int n, k;
        scanf("%d%d", &n, &k);
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        int ptr = 0;
        bool out = true;
        for (; ptr < n; ++ptr) {
            if (a[ptr] == b[ptr]) {
                continue;
            }
            int l, r;
            bool flag = false;
            if (ptr - k < 0) {
                l = 0;
            } else {
                l = ptr - k;
            }
            if (ptr + k > n) {
                r = n;
            } else {
                r = ptr + k;
            }
            for (;l <= r; ++l) {
                if (l == ptr) {
                    continue;
                }
                if (a[l] == b[ptr]) {
                    a[ptr] = a[l];
                    flag = true;
                    break;
                }
            }
            if (flag) {
                out = true;
                continue;
            } else {
                out = false;
                break;
            }
        }
        printf(out ? "Yes\n" : "No\n");
    }
    return 0;
}