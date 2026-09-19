#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<ll> a(n);
    vector<ll> b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    ranges::sort(a), ranges::sort(b);
    auto kbalance = y * k;
    ll ans = 0;
    for (auto i : b) {
        auto consume = i / k + (bool)i % k;
        if (y >= consume) {
            y -= consume;
            kbalance -= consume * k;
            x += (consume * k - i);
            ans++;
        } else {
            break;
        }
    }
    auto balance = kbalance + x;
    for (auto i : a) {
        balance -= i;
        if (balance < 0) {
            break;
        } else {
            ans++;
        }
    }
    cout << ans << '\n';
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