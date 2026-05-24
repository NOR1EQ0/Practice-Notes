#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    string s;
    cin >> s >> s;
    ll n = s.size();
    char cur = s.front();
    ll total = n * (n + 1) / 2;
    ll bad{};
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] == s[i]) ++j;
        ll len = j - i;
        bad += len * (len + 1) / 2;
        i = j;
    }

    cout << (total - bad) << '\n';
}
int main() {
#if defined(ONLINE_JUDGE) || 1
    ios::sync_with_stdio(0), cin.tie(0);
#elif 10
    freopen("1.in", "rb", stdin);
#endif
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}