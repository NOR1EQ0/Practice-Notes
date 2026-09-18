#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> xv(n), yv(n);
    for (auto&& i : xv) cin >> i;
    for (auto&& i : yv) cin >> i;
    vector<ll> p1(n), p2(n);
    iota(p1.begin(), p1.end(), 0);
    iota(p2.begin(), p2.end(), 0);
    sort(p1.begin(), p1.end(), [&](auto&& lhs, auto&& rhs) { return std::less()(xv[lhs], xv[rhs]); });
    sort(p2.begin(), p2.end(), [&](auto&& lhs, auto&& rhs) { return std::less()(yv[lhs], yv[rhs]); });
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        p[p1[i]] = p2[n - 1 - i];
    }
    for (auto it = p.begin(); it != p.end(); it++) {
        cout << *it + 1 << " \n"[it + 1 == p.end()];
    }
}
int main() {
#if defined(ONLINE_JUDGE) || 1
    ios::sync_with_stdio(0), cin.tie(0);
#elif 10
    freopen("1.in", "rb", stdin);
#endif
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}