#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int x = arr[n - 1];
        int i;
        for (i = n - 1; i > 0; --i) {
            if (arr[i - 1] > x / 2) break;
        }
        printf("%d\n", i + 1);
    }
    return 0;
}
