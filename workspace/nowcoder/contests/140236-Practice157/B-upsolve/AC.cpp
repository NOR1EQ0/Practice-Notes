#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
using PLL = pair<ll, ll>;
ll mex(set<ll>& s) {
    auto n = s.size();
    vector<bool> vis(n + 1, false);
    for (auto x : s) {
        if (x >= 0 && x <= n) {
            vis[x] = true;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) return i;
    }
    return n + 1;
}
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto& i : v) cin >> i;
    ranges::sort(v);
    vector<ll> x(n);
    x[0] = v[0];
    ll k = x[0] - v[0];
    for (int i = 1; i < n; i++) {
        x[i] = max(x[i - 1] + 1, v[i]);
        k = max(k, x[i] - v[i]);
    }
    k = k / 2 + k % 2;
    cout << k << '\n';
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