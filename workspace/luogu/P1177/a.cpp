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

inline int partition(vector<int>& num, int l, int r) {
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
    using namespace std::chrono;
    using chrono::system_clock;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("P1177_5.in", "r", stdin);
    int n; cin >> n;
    vector<int> vec(n);
    // auto readbegin = system_clock::now();
    for (size_t i = 0;i < n;++i)cin >> vec[i];
    // auto readend = system_clock::now();
    // auto sortbegin = system_clock::now();
    quick_sort(vec, 0, vec.size() - 1);
    // auto sortend = system_clock::now();
    // auto outputstart = system_clock::now();
    for (auto i = vec.begin(); i != vec.end() - 1; ++i) {
        cout << *i << ' ';
    }
    // auto outputend = system_clock::now();
    cout << vec.back();
    cout.put('\n');
    // {
    //     cout << "Read start from " << system_clock::to_time_t(readbegin) <<
    //         " to " << system_clock::to_time_t(readend) <<
    //         ": " << duration_cast<milliseconds>(readend - readbegin).count() << "ms\n" <<
    //         "Sort start from " << system_clock::to_time_t(sortbegin) <<
    //         " to " << system_clock::to_time_t(sortend) <<
    //         ": " << duration_cast<milliseconds>(sortend - sortbegin).count() << "ms\n" <<
    //         "Output start from " << system_clock::to_time_t(outputstart) <<
    //         " to " << system_clock::to_time_t(outputend) <<
    //         ": " << duration_cast<milliseconds>(outputend - outputstart).count() << "ms\n";
    // }
    return 0;
}