#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n, m, tmp;
    scanf("%d%d", &n, &m);
    int arr[m][2];
    // 0 = essay, 1 = count
    memset(arr, 0, sizeof(int) * m * 2);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        bool flag[m];
        memset(flag, false, sizeof(bool) * a);
        for (int j = 0; j < a; ++j) {
            scanf("%d", &tmp);
            tmp--;
            arr[tmp][1]++;
            if (flag[tmp] == false) {
                flag[tmp] = true;
                arr[tmp][0]++;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
    return 0;
}