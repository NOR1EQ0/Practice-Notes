#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static inline void solve() {
    ll n, m;
    cin >> n >> m;
    string row;
    cin >> row;
    ll cnt = m;
    while (m--) {
        row[0] = row[0] == '0' ? '1' : '0';
        ll idx = 0;
        while (1) {
            idx = row.find(row[idx], idx + 1);
            if (idx != string::npos) {
                cnt++;
                row[idx] = row[idx] == '0' ? '1' : '0';
            } else {
                break;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
#if defined(ONLINE_JUDGE) || 1
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}