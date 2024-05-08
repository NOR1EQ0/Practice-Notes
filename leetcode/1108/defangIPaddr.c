#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *defangIPaddr(char *address)
{
    char *ans = (char *)malloc(sizeof(char) * (strlen(address) + 6));
    // memset(ans, '\0', sizeof(char) * strlen(address) + 6);
    printf("%d", strlen(address));
    char *p = ans, *s = address;
    while (s < address + (char)strlen(address))
    {
        if (*s >= '0' && *s <= '9')
        {
            *p = *s;
            p++;
        }
        else
        {
            memcpy(p, "[.]", sizeof(char) * 3);
            p += 3;
        }
        s++;
    }
    return ans;
}

int main()
{
    char *address = "255.100.50.0";
    char *ans = defangIPaddr(address);
    printf("%s\n", ans);
    return 0;
}