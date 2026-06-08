#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c : s) {
        m[c]++;
    }
    ll cnt=0;
    for (auto [l, r] : m) {
        if(r==1)cnt++;
    }
    cout << cnt << '\n';
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