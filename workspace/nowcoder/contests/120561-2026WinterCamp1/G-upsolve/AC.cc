#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ll l, r;
    cin >> l >> r;
    string rs = to_string(r);
    if (l == r) {
        ranges::reverse(rs);
        cout << rs << '\n';
        return;
    }
    if (ranges::count(rs, '0') == rs.size() - 1 && rs[0] == '1') {
        cout << r - 1 << '\n';
        return;
    }
    ll ans = max(stoll('1' + string(rs.size() - 1, '0')), l);
    string s = string(18, '0') + to_string(ans);
    for (ll i = 1, j = s.size() - 1; i <= 1e16 && j >= 0; i *= 10, j--) {
        for (int k = 1; k <= '9' - s[j]; k++) {
            if (ans + i <= r) ans += i;
        }
    }
    ranges::reverse(s = to_string(ans));
    cout << s << '\n';
}
#define ONLINE_JUDGE
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    0;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}