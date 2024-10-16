#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        char s[101];
        char s2[101];
        scanf("%s", s);
        scanf("%s", s2);
        int len1 = strlen(s), len2 = strlen(s2), j = 0, sec = 0;
        for (j = 0; j < len1; ++j) {
            if (s[j] != s2[j]) {
                break;
            }
        }
        sec += j + ((len1 - j) >= 0 ? (len1 - j) : 0) + ((len2 - j) >= 0 ? (len2 - j) : 0);
        if (j) {
            j++;
        }
        sec += (bool)j;

        printf("%d\n", sec);
    }
    return 0;
}