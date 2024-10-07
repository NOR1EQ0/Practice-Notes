#include <stdio.h>
#include <string.h>

int main() {
    char str[31];
    scanf("%s", str);
    if (strcmp(str + strlen(str) - 3, "san"))
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}