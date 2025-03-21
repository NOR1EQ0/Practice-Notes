#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alternateDigitSum(int n) {
    char str[64];
    int ans = 0;
    memset(str, '\0', sizeof(char) * 64);
    sprintf(str, "%d", n);
    for (char* ptr = str; *ptr; ++ptr) {
        if ((ptr - str)%2) {
            ans += -(*ptr - '0');
        } else {
            ans += (*ptr - '0');
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int a = alternateDigitSum(521);
    return 0;
}
