#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        if (t[i] != '*' && t[i] != s[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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