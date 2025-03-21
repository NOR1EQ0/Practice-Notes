#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int l, m; // road.len areas
    scanf("%d %d", &l, &m);
    l++; // real trees count
    bool arr[l];
    memset(arr, true, sizeof(bool) * l);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        memset(arr + a, false, sizeof(bool) * (b - a + 1));
    }
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        if (arr[i])
            ans++;
    }
    printf("%d", ans);
    return 0;
}