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

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (j == 0) {
                    for (int k = 0; k < n; ++k) {
                        if (arr[k] != 0) {
                            bus[i][j] = k;
                            arr[k]--;
                            ans++;
                            break;
                        }
                    }
                }
                else {
                    for (int k = 0; k < n; ++k) {
                        if (k == bus[i][0] && arr[k] != 0) {
                            bus[i][1] = k;
                            arr[k]--;
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) { ans -= arr[i]; }
        printf("%d\n", ans);
    }

    return 0;
}
