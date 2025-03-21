#include <stdio.h>

int main(int argc, char const* argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char a[6];
        scanf("%s", a);
        char* ptr = a;
        for (;*ptr == '0'; ptr++);
        printf("%s\n", *ptr ? ptr : "0");
    }

    return 0;
}
