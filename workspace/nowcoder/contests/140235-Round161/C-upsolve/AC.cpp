#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ull> v(n);
    for (auto& i : v) cin >> i;
    ranges::sort(v, [](ull lhs, ull rhs) -> bool {
        auto p1 = popcount(lhs), p2 = popcount(rhs);
        if (p1 != p2) {
            return p1 < p2;
        }
        auto c1 = lhs ? countr_zero(lhs) : 31,
             c2 = rhs ? countr_zero(rhs) : 31;
        if (c1 != c2) {
            return c1 < c2;
        }
        return lhs < rhs;
    });
    cout << v[k - 1] << '\n';
}
int main() {
#if defined(ONLINE_JUDGE) || 1
    ios::sync_with_stdio(0), cin.tie(0);
#elif 10
    freopen("1.in", "rb", stdin);
#endif
    ll t = 1;
    while (t--) {
        solve();
    }
}