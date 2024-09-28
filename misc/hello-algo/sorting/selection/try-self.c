#include <stdio.h>
#include "../sortutil.h"

void sort(int* nums, int n) {
    int min = nums[0];
}

int main() {
    int nums[6] = { 4,1,3,1,5,2 };
    print_array(nums, 6, true);
    sort(nums, 6);
    print_array(nums, 6, true);
}