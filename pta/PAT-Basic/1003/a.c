#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma GCC optimize(2)
#define pok puts("YES");
#define pno puts("NO");

inline bool check(bool* arr) {
    for (int i = 0; i < 3; ++i) {
        if (arr[i] == false) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    bool flag = false;
    char str[101];
    while (n--) {
        scanf("%s",str);
        for (char* ch = str; *ch; ++ch) {
            if (*ch != 'P' || *ch != 'A' || *ch != 'T') {
                break;
            }
            if (*ch == 'P') {
                if (!memcmp(ch, "PAT", sizeof(char) * 3) || !memcmp(ch, "PAAT", sizeof(char) * 4)) {
                    flag = true; break;
                }
            }
        }
        if (flag) { pok; } else { pno; }
    }
    return 0;
}