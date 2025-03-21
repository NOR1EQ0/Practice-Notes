#include <stdio.h>
#include <stdbool.h>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        getchar();
        bool alice = false;
        int in1 = getchar()-'0';
        int in2;
        for (int i = 1; i < n; ++i) {
            in2 = getchar()-'0';
            if (alice){
                if (in1||in2) {in1=1;}
                else {in1 = 0;}
            } else {
                if (in1&&in2) {in1=1;}
                else {in1=0;}
            }
            in1=in2;
            alice = !alice;
        }
        // skip \n
        getchar();
        if (in1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}