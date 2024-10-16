#include <stdio.h>

int main() {
    int x,n;
    scanf("%d%d",&x,&n);
    x-=n*10;
    printf("%d\n",x/20);
    return 0;
}