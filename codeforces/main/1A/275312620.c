#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long int n, m, a;
    scanf("%lld %lld %lld", &n, &m, &a);
    n = n%a ? n/a+1: n/a;
    m = m%a ? m/a+1: m/a;
    printf("%lld",n * m);
    return 0;
}