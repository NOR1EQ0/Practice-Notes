#include <bits/stdc++.h>

using namespace std;

inline int medianThree(vector<int>& vec, int left, int middle, int right) {
    const int l = vec[left], m = vec[middle], r = vec[right];
    if (
        (l >= m && l <= r) || (l >= r && l <= m)
        ) return left;
    if (
        (m >= l && m <= r) || (m >= r && m <= l)
        ) return middle;
    return right;
}

int partition(vector<int>& num, int l, int r) {
    auto mid = (l + r) / 2;
    auto median = medianThree(num, l, mid, r);
    swap(num[median], num[l]);
    int i = l, j = r;
    while (i < j) {
        while (i < j && num[j] >= num[l]) j--;
        while (i < j && num[i] <= num[l]) i++;
        swap(num[i], num[j]);
    }
    swap(num[l], num[i]);
    return i;
}

void quick_sort(vector<int>& num, int l, int r) {
    auto len = num.size();
    while (l < r) {
        auto pivot = partition(num, l, r);
        if (pivot - l < r - pivot) {
            quick_sort(num, l, pivot - 1);
            l = pivot + 1;
        } else {
            quick_sort(num, pivot + 1, r);
            r = pivot - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> vec(n);
    for (size_t i = 0;i < n;++i)cin >> vec[i];
    quick_sort(vec, 0, vec.size() - 1);
    return 0;
}