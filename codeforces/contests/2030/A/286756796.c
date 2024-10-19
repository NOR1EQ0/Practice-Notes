#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        scanf("%d", &a[0]);
        int max = *a, min = *a;
        for (int i = 1; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] > max) {
                max = a[i];
            }
            if (a[i] < min) {
                min = a[i];
            }
        }
        printf("%d\n",(n-1)*(max-min));
    }
    return 0;
}
