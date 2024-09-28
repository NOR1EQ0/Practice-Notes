#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
    
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber(const int N) {
    // sqrt
    int arg1 = N;
    int rt = sqrt(arg1);
    if (rt*rt != N)
        return 0;
    int len = 1;
    // count bit
    for (;arg1 >= 10;) {
        arg1 /= 10;
        len++;
    }
    char str[len+1];
    sprintf(str, "%d", N);
    for (int i = 0; i < len + 1; ++i) {
        for (int j = i + 1; j < len + 1; ++j) {
            if (str[i] == str[j])
                return 1;
        }
    }
    return 0;
}