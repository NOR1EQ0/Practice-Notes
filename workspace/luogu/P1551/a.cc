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
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    size_t n, m, p;
    cin >> n >> m >> p;
    dsu d1(n);
    while (n--) {
        size_t i, j;
        cin >> i >> j;
    }
}