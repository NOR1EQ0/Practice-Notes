#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll ansCnt[3]{};
    for (auto&& i : v) {
        cin >> i;
        if (i % 2) {
            ansCnt[1]++;
        } else {
            bool flg = i / 2 % 2;
            ansCnt[2 * flg]++;
        }
    }
    ll mx = 0;
    for (auto i: ansCnt) {
        mx = max(mx, i);
    }
    cout << mx << '\n';
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