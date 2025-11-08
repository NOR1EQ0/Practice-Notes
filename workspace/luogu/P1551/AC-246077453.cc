#include <bits/stdc++.h>

using namespace std;
using ll = long long;

size_t groups = 0;

struct dsu {
    vector<size_t> arr;

    template <typename T, typename = enable_if_t<is_integral_v<T>>>
    explicit dsu(T __n) : arr(__n + 1) { iota(arr.begin(), arr.end(), 0); }

    size_t find(size_t __target) {
        return arr[__target] == __target ? __target : arr[__target] = find(arr[__target]);
    }

    void unite(size_t __t1, size_t __t2) {
        arr[find(__t1)] = find(__t2);
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    size_t n, m, p;
    cin >> n >> m >> p;
    dsu d1(n);
    while (m--) {
        size_t i, j;
        cin >> i >> j;
        d1.unite(i, j);
    }

    while (p--) {
        size_t i, j;
        cin >> i >> j;
        auto ifind = d1.find(i);
        auto jfind = d1.find(j);
        if (ifind == jfind) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}