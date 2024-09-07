#include <stdio.h>
#include <string.h>

void force(char* str) {
    for (char* ptr = str; *ptr; ++ptr) {
        if (*ptr < 'a') {
            *ptr += 32;
        }
    }
}

int main() {
    int wd1, wd2;
    printf("%c", 'A' + 0x20);
    scanf("%d%d", &wd1, &wd2);
    char a[wd1][11];
    char b[wd2][11];
    int stk_a = 0, stk_b = 0;

    for (int i = 0; i < wd1; ++i) {
        scanf("%s", a[i]);
        force(a[i]);
        
    }
    for (int i = 0; i < wd2; ++i) {
        scanf("%s", b[i]);
        force(b[i]);
    }
    int dict_len = wd1 > wd2 ? wd2 : wd1;
    char dict[dict_len][11];
    int dict_ptr = 0;
    memset(dict, '\0', dict_len * 11 * sizeof(char));

    return 0;
}