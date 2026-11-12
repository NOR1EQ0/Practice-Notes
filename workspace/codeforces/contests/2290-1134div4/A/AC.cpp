#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll arr[3];
    for (auto& i : arr) cin >> i;
    ranges::sort(arr);
    if (arr[2] - arr[1] == 1 && arr[1] - arr[0] == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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