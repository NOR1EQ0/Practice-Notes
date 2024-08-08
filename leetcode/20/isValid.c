#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[strlen(s) / 2];
    int ptr = -1;
    for (;*s;++s) {
        if (*s == '(' || *s == '[' || *s == '{') {
            ptr++;
            stack[ptr] = *s;
            continue;
        }
        if (ptr < 0) {
            return false;
        }
        if (*s == ')') {
            if (stack[ptr] == '(') {
                ptr--;
                continue;
            }

        }
        if (*s == ']') {
            if (stack[ptr] == '[') {
                ptr--;
                continue;
            }
        }
        if (*s == '}') {
            if (stack[ptr] == '{') {
                ptr--;
                continue;
            }
        }
        return false;
    }
    return ptr == -1;
}