#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solve(int n, int a[]) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] + a[j] == 0) ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int ans = solve(n, arr);
    printf("%d\n",ans);
    return 0;
}
