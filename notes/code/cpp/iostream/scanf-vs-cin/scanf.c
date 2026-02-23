#include <stdint.h>
#include <stdio.h>

int main() {
    freopen("data.txt", "rb", stdin);
    uint_fast64_t tmp;
    while (scanf("%lu", &tmp) != EOF);
}