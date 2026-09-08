#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 1e9 + 7;
ll fib[(int)1e5 + 5];
static inline void init() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= (int)1e5; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
}
static inline void solve() {
    init();
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);

    for (auto& i : v) {
        cin >> i;
        i = fib[i];
    }

    vector<ll> presum(n);
    presum[0] = v[0];
    for (ll i = 1; i < n; i++) {
        presum[i] = (presum[i-1] + v[i]) % MOD;
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (l == 1) {
            cout << presum[r - 1] << '\n';
        } else {
            cout << (presum[r - 1] - presum[l - 2] + MOD) % MOD << '\n';
        }
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