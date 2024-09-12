#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char str[3];
        scanf("%s", str);
        if (*str == str[1] || *str == str[2]) {
            continue;
        }
        if (str[1] == str[2]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
