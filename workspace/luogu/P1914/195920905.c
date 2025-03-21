#include <stdio.h>
#define a 'a'
#define z 'z'

int main() {
    int n;
    char str[51];
    scanf("%d",&n);
    scanf("%s",str);
    for (char* i = str; *i; ++i) {
        if (*i + n > z) {
            *i = n + *i - 26;
        } else {
            *i += n;
        }
    }
    printf("%s\n", str);
    return 0;
}