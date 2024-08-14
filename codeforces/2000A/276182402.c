#include <stdio.h>
#include <string.h>

int main() {
    char str[32];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        int len = strlen(str);
        if (len < 3) {
            printf("NO\n");
            continue;
        }
        if (str[0] == '1' && str[1] == '0') {
            if (str[2] == '0') {
                printf("NO\n");
                continue;
            }
            if (len == 3 && str[2] == '1') {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}