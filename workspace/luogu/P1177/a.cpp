#include <bits/stdc++.h>

using namespace std;

inline void print_vector_no_space_at_last(vector<int>& num, bool lf = true) {
    for (auto i = num.begin(); i != num.end() - 1; ++i) cout << *i << ' '; cout << num.back();
    if (lf) cout << '\n';
}

int partition(vector<int>& num, int l, int r) {
    
}

void quick_sort(vector<int>& num, int l, int r) {
    auto len = num.size();
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> vec(n);
    for (size_t i = 0;i < n;++i)cin >> vec[i];
    quick_sort(vec);
    print_vector_no_space_at_last(vec);
    return 0;
}