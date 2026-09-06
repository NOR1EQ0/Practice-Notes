#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    ll arr[4]{};
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        arr[p]++;
    }
    unsigned flg = 0u;
    for (int i = 1; i <= 3; i++) {
        if (arr[i] % 2) {
            flg |= (1u << (i - 1));
        }
    }
    static int ans[8] = {
        0, 1, 2, 1, 3, 2, 1, 0
    };
    cout << ans[flg] << '\n';
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