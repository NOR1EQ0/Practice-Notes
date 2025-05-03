#include <bits/stdc++.h>
#include "../../utils/print"

using namespace std;

int medianThree(vector<int>& vec, int left, int middle, int right) {
    const int l = vec[left], m = vec[middle], r = vec[right];
    if (
        (l >= m && l <= r) || (l >= r && l <= m)
    ) return left;
    if (
        (m >= l && m <= r) || (m >= r && m <= l)
    ) return middle;
    return right;
}

int partition(vector<int>& vec, int left, int right) {
    int i = left, j = right;
    while (i<j) {
        while (i<j && vec[j] >= vec[left]) j--;
        while (i<j && vec[i] <= vec[left]) i++;
        swap(vec[i], vec[j]);
    }
    swap(vec[left], vec[i]);
    return i;
}

int partition_median(vector<int>& vec, int left, int right) {
    int mid = left + (right - left) / 2;
    auto median = medianThree(vec, left, mid, right);
    swap(vec[median], vec[left]); // 中位数移动至最左端作为基准数
    int i = left, j = right;
    while (i<j) {
        while (i<j && vec[j] >= vec[left]) j--;
        while (i<j && vec[i] <= vec[left]) i++;
        swap(vec[i], vec[j]);
    }
    swap(vec[left], vec[i]);
}

// basic algo
void quick_sort(vector<int>& vec, int left, int right) {
    if (right <= left) return;
    auto pivot = partition(vec, left, right);
    quick_sort(vec, left, pivot - 1);
    quick_sort(vec, pivot + 1, right);
}

// median + tail recursion
void quick_sort_median(vector<int>& vec, int left, int right) {
    while (left < right) {
        auto pivot = partition(vec, left, right);
        if (pivot - left < right - pivot) {
            quick_sort_median(vec, left, pivot - 1);
            left = pivot + 1;
        } else {
            quick_sort_median(vec, pivot + 1, right);
            right = pivot - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vec;
    return 0;
}