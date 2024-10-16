#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0) {
            printf(b % 2 ? "NO\n" : "YES\n");
            continue;
        }
        if (b == 0) {
            printf(a % 2 ? "NO\n" : "YES\n");
            continue;
        }
        if (a % 2) {
            printf("NO\n");
        } else {
            if (a / 2 <= b + 1) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}