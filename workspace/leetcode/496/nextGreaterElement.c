#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * nums1Size);
    int* ptr = ans;
    for (int* ptr1 = nums1; ptr1 < nums1 + nums1Size; ++ptr1, ++ptr) {
        int* ptr2 = nums2;
        for (int* tmpptr = ptr2; tmpptr < nums2 + nums2Size; ++tmpptr) {
            if (*tmpptr == *ptr1) {
                ptr2 = tmpptr;
                break;
            }
        }
        while (ptr2 < nums2 + nums2Size) {
            if (*ptr2 > *ptr1) {
                *ptr = *ptr2;
                break;
            }
            ++ptr2;
        }
        if (ptr2 == nums2 + nums2Size) {
            *ptr = -1;
        }
    }
    *returnSize = nums1Size;
    return ans;
}