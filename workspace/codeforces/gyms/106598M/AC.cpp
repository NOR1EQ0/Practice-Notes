#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    string s, t;
    ll p, q;
    cin >> s >> t >> p >> q;
    if (!p || !q) {
        cout << '0';
    } else {
        string s1 = s + t,
               s2 = t + s;
        auto order = s1 <=> s2;
        if (order < 0) {
            cout << '<';
        } else if (order == 0) {
            cout << '=';
        } else {
            cout << '>';
        }
    }
    cout << '\n';
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