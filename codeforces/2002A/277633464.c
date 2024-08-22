#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", (m < k ? m : k) * (n < k ? n : k));
    }
    return 0;
}