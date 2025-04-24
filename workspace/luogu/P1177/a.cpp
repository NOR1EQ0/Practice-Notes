#include <bits/stdc++.h>

using namespace std;

inline void print_vector_no_space_at_last(vector<int>& num, bool lf = true) {
    for (auto i = num.begin(); i != num.end() - 1; ++i) cout << *i << ' '; cout << num.back();
    if (lf) cout << '\n';
}

void insertion_sort(vector<int>& num) {
    auto len = num.size();
    for (size_t i = 1; i < len; ++i) {
        int key = num[i];
        int j = i - 1;
        while (j >= 0 and num[j] > key) {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = key;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> vec(n);
    for (size_t i = 0;i < n;++i)cin >> vec[i];
    insertion_sort(vec);
    print_vector_no_space_at_last(vec);
    return 0;
}