#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit ( const int N, const int D ) {
    int len = 1, arg1 = N, ans = 0;
    // count bit
    for (;arg1 >= 10;) {
        arg1 /= 10;
        len++;
    }
    char str[len + 2];
    sprintf(str,"%d",N);
    for (char *ptr = str; *ptr; ++ptr) {
        if (*ptr - '0' == D) ans++;
    }
    return ans;
}