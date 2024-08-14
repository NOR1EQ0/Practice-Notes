#include <stdio.h>

int main() {
    char c;
    scanf("%c",&c);
    printf("%c",c ^ ('A' ^ 'a'));
    return 0;
}