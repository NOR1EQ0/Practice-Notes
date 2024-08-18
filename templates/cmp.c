/**
 * qsort 比较函数
 */
#include <string.h>

// 升序
int cmp(const void* a, const void* b) {
    return (*(const int*)a > *(const int*)b) - (*(const int*)a < *(const int*)b);
}

// 降序
int cmp(const void* a, const void* b) {
    return (*(const int*)a < *(const int*)b) - (*(const int*)a > *(const int*)b);
}