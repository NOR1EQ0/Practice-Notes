#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n), l(m), r(m);
    for (auto& i : p) cin >> i;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    
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