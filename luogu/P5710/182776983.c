#include <stdio.h>
#define bool _Bool
int main() {
    int n;
    int a[4] = { 0,0,0,0 };
    scanf("%d", &n);
    bool flag1 = !(n % 2), flag2 = (n > 4 && n <= 12);
    if (flag1 ^ flag2) {
        a[1] = 1;
        a[2] = 1;
    }
    else {
        if (flag1 && flag2) {
            a[0] = 1;
            a[1] = 1;
        } else {
            a[3] = 1;
        }
    }
    printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
    return 0;
}
