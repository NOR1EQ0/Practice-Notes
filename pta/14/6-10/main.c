#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N ) {
    if (N < 0) {
        printf("Invalid input\n");
        return;
    }
    typedef long long i64;
    i64 copy = N, ans = 1;
    for (i64 i = 1; i <= copy; ++i) {
        ans *= i;
    }
    printf("%lld\n", ans);
}

char* multiply(int x, int y) {
    int x_len = 1, y_len = 1;
    while (x >= 10) {
        x /= 10;
        x_len++;
    } 
    while (y >= 10) {
        y /= 10;
        y_len++;
    }

    char x_str[x_len], y_str[y_len], ans[x_len + y_len];
    sprintf(x_str, "%d", x);
    sprintf(y_str, "%d", y);
    for (int i = 0; i < x_len; ++i) {
        x_str[i] -= '0';
    }
    for (int i = 0; i < y_len; ++i) {
        y_str[i] -= '0';
    }

}