#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    ll lost = 0;
    while (n--) {
        char str[5];
        ll v, c;
        cin >> v >> c >> str;
        if (str[0] == 'k') {
            lost += (c - v);
        }
    }
    cout << lost << '\n';
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