#include <stdio.h>

int main() {
    char str[3];
    int ans = 0;
    scanf("%s", str);
    for (int i = 0; i < 3; ++i) {
        if (str[i] == '1')
        ans++;
    }
    printf("%d", ans);
    return 0;
}