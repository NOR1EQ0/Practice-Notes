#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r, ans = 0;
        scanf("%d%d", &n, &r);
        int arr[n], bus[r][2];
        memset(bus, -1, sizeof(int) * r * 2);
        for (int i = 0; i < n; ++i) { scanf("%d", &arr[i]); } // read

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < r; ++j) {
                // fill 
                for (int k = 0; k < n; ++k) {
                    if (arr[k] == 0 || k == bus[j][1 - i]) continue;
                    bus[j][i] = k; arr[k]--;
                    break;
                }
            }
        }

        // happy count
        for (int i = 0; i < r; ++i) {
            if (bus[i][0] == bus[i][1]) continue;
            ans++;
            if (bus[i][0] != -1 && bus[i][1] != -1) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
