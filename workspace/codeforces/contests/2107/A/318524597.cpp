#include <bits/stdc++.h>
#define pno cout << "No\n"
#define pok cout << "Yes\n"

using namespace std;

template<typename iter>
vector<int> prefixgcd(iter begin, iter last) {
    auto len = distance(begin, last);
    if (!len) return {};
    vector<int> ret;
    ret.reserve(len-1);
    ret.emplace_back(*begin);
    auto current_gcd = *begin;
    for (auto i = next(begin); i != prev(last); ++i) {
        ret.emplace_back(current_gcd = gcd(current_gcd, *i));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    vector<int> vec;
    vec.reserve(100);
    while (t--) {
        int n;cin >> n;vec.resize(n);
        for (int i = 0;i < n;++i) cin >> vec[i];
        auto left = prefixgcd(vec.begin(), vec.end());
        auto right = prefixgcd(vec.rbegin(), vec.rend());
        int divpos = -1;
        for (int i = 0; i < n-1; ++i) {
            auto left_cur = left.begin() + i;
            auto right_cur = right.rbegin() + i;
            if (*left_cur != *right_cur) {
                divpos = i;
                break;
            }
        }
        if (divpos+1) {
            pok;
            for (int i = 0; i <= divpos; ++i) {
                cout<<"1 ";
            }
            for (int i = divpos + 1; i < n-1;++i) cout<<"2 ";
            cout << "2\n";
        } else {
            pno;
        }
    }
    return 0;
}