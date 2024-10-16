#include <stdio.h>

typedef unsigned long long ull;
int main(){
	int num;
	scanf("%d", &num);              	                  // Reading input from STDIN
    ull ans = 0;
	for (int i = 0; i < num; i++) {
        ull in;
        scanf("%llu", &in);
        ans += in;
    }
    printf("%llu", ans);
    return 0;
}
