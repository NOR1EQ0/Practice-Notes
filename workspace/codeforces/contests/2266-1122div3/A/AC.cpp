#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    ll arr[3];
    cin >> n;
    ranges::for_each(arr, [](auto& i) { cin >> i; });
    ranges::sort(arr);
    ll ans = (arr[2] - arr[0]) + (n - arr[2]);
    cout << ans << '\n';
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