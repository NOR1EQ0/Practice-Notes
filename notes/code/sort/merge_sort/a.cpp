#include <bits/stdc++.h>
#include "../../utils/print" 

using namespace std;

inline void merge(vector<int>& nums, int left, int mid, int right) {
    auto len = nums.size();
    vector<int> tmp(len);
    size_t i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] > nums[j]) tmp[k++] = nums[j++];
        else tmp[k++] = nums[i++];
    }
    while (i <= mid) {
        tmp[k++] = nums[i++];
    }
    while (j <= mid) {
        tmp[k++] = nums[j++];
    }
    for (k = 0;left <= right;left++, k++) {
        nums[left] = tmp[k];
    }
}

// 分治递归实现
void merge_sort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid+1, right);
    merge(nums, left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vec;
    print_stl_container_element_with_newline(vec);
    return 0;
}