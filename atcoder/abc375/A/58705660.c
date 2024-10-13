#include <stdio.h>

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    char in = getchar();
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        in = getchar();
        if (in == '#') {
            if (flag == 0) {
                flag = 1;
            } else if (flag == 2) {
                ans++;
                n--;
                if ((in = getchar()) == '.') {
                    flag = 2;
                } else {
                    flag = 1;
                }
            }
        } else if (in = '.') {
            if (flag == 1) {
                flag = 2;
            } else if (flag == 2) {
                flag = 0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}