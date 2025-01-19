#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

size_t p10(int len);
inline size_t p10(int len) {
    size_t ans = 1;
    for (int i = 0; i < len; ++i) {
        ans *= 10;
    }
    return ans;
}

int myAtoi(char* s) {
    char* ptr = s;
    uint64_t ans = 0;
    bool minus = false;
    int len = 0;
    for (;*ptr == ' '; ptr++);
    // check minus
    if (*ptr == '-') {
        minus = true;
        ptr++;
    } else if (*ptr == '+') {
        minus = false;
        ptr++;
    }
    
    // skip leading zero
    for (; *ptr == '0'; ptr++);
    char* begin = ptr;
    for (; *ptr >= '0' && *ptr <= '9'; ptr++);
    for (begin != ptr ? ptr-- : ptr; *ptr >= '0' && *ptr <= '9' && ptr >= begin; ptr--, len++) {
        ans += (uint64_t)(*ptr - '0') * p10(len);
        if (len>10) {
            if (minus) return INT32_MIN;
            else return INT32_MAX;
        }
        if (ans >= INT32_MAX) {
            if (!minus) {
                return INT32_MAX;
            } else {
                return ans >= (uint64_t)(INT32_MAX)+1 ? INT32_MIN : -INT32_MAX;
            }
        }
        if (ptr == begin) {
            break;
        }
    }
    return (int)(minus? -ans : ans);
}


int main() {
    char str[201];
    fgets(str, 201, stdin);
    printf("%d\n", myAtoi(str));
    return 0;
}