#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll x, y;
    cin >> x >> y;
    bool alice = false;
    if (x < y) swap(x, y);
    auto n = (x - y) / 3;
    x -= 2 * n;
    y += n;
    if (n & 1) {
        alice = !alice;
    }
    if (x - y > 1) {
        alice = !alice;
    }
    cout << (alice ? "Alice\n" : "Bob\n");
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