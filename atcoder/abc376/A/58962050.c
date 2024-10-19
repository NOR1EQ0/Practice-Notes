#include <stdio.h>

int main() {
    int n,c;
    scanf("%d%d", &n,&c);
    int in;
    int ans=1;
    int recv;
    scanf("%d",&recv);
    for (int i = 1; i < n; ++i) {
        scanf("%d",&in);
        if (in-recv>=c) {
            ans++;
            recv=in;
        }
    }
    printf("%d\n",ans);
    return 0;
}