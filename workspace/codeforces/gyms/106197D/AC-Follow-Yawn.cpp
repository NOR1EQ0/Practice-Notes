#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;

static inline void solve() {
    uint32_t n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans;
    for (auto c : s) {
        if (k & 1) k -= (c == '+' ? 1 : -1), ans += '#';
        else
            ans += '.';
        k >>= 1;
    }
    cout << (k ? "-1" : ans) << '\n';
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