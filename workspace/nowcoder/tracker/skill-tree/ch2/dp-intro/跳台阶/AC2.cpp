#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << n - 1 << '\n';
        return;
    }
    ll a = 1, b = 2;
    ll state = a + b;
    for (ll i = 5; i <= n; i++) {
        a = b;
        b = state;
        state = (a + b) % MOD;
    }
    cout << state << '\n';
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