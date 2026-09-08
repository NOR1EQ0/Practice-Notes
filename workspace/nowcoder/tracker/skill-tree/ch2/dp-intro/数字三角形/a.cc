#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;

ll hill[505][505];
static inline void solve() {
    ll n;
    cin >> n;
    ll mx = LLONG_MIN;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < i + 1; j++) {
            cin >> hill[i][j];
            if (i == 0) {
                mx = hill[i][j];
                continue;
            }
            if (j == 0) {
                hill[i][j] += hill[i - 1][j];
            } else if (j == i) {
                hill[i][j] += hill[i - 1][j - 1];
            } else {
                hill[i][j] += max(hill[i - 1][j - 1], hill[i - 1][j]);
            }
        }
    }
    mx = *max_element(hill[n-1], hill[n-1] + n);
    cout << mx << '\n';
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