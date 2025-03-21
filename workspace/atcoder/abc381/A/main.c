#include <stdio.h>
#define pno puts("No")
#define pok puts("Yes")

int main() {
    int i = 0;
    int n;
    scanf("%d", &n);
    int num = (n + 1) / 2 - 1;
    int one = 0, two = 0;
    char str[n + 1];
    scanf("%s", str);
    if (strlen(str) == 1 && *str == '/') {
        pok; return 0;
    }
    for (i = 0; i < (n + 1) / 2 - 1; ++i) {
        if (str[i] != '1') {
            pno; return 0;
        }
        one++;
    }
    if (str[i++] != '/') { pno;return 0; }
    for (;i < n ;++i) {
        if (str[i] != '2') {
            pno; return 0;
        }
        two++;
    }
    pok;
    return 0;
}