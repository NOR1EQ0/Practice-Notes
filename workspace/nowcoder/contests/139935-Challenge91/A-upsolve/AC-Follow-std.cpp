#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    ll arr[4]{};
    while (n--) {
        ll x;
        cin >> x;
        arr[x]++, sum += x;
    }
    ll tar = sum / 2, best = 0;
    for (ll k3 = 0; k3 <= arr[3] && 3ll * k3 <= tar; k3++) {
        ll cur = k3 * 3ll, rem = tar - cur;
        cur += 2 * min<ll>(arr[2], rem / 2);
        cur += min<ll>(arr[1], tar - cur);
        best = max(best, cur);
    }
    cout << sum - 2 * best << '\n';
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