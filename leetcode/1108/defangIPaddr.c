#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *defangIPaddr(char *address)
{
    char *ans = (char *)malloc(sizeof(char) * (strlen(address) + 6));
    char *p = ans, *s = address;
    while (s < address + (char)strlen(address))
    {
        if (*s >= '0' && *s <= '9')
        {
            
        }
        
    }
}