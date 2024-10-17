#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        char str[n + 1];
        scanf("%s", str);
        for (int i = 0; i < n; ++i) {
            int j = i;
            for (; j < n; ++j) {
                if (str[j] == str[i]) {
                    j++;
                    break;
                }
            }
            int k = j;
            for (; k < n; k++) {
                if (str[k] == str[j]) {
                    i = j;
                    j = k + 1;
                    break;
                }
            }
        }
    }
    return 0;
}