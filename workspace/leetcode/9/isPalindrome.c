#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x) {
    char buf[16] = "";
    sprintf(buf, "%d", x);
    char* head = buf;
    char* tail = buf + strlen(buf) - 1;
    if (*tail == '-')
    {
        return false;
    }
    for (;tail > head;++head, --tail) {
        if (*head != *tail) {
            return false;
        }
    }
    return true;
}

int main() {
    isPalindrome(121);
}