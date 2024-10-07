#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll unsigned long long
#define max 1000000000

int main() {
    char in;
    int len = 1, bit = 1;
    ll* arr = (ll*)malloc(sizeof(ll));
    while ((in = getchar()) != '\n') {
        len++, bit++;
        arr = (ll*)realloc(arr, sizeof(ll)*len);
    }
}