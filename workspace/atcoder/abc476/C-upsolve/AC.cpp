#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto&& i : v) {
        cin >> i;
    }
    ll arr[3]{};
    copy(v.begin(), v.begin() + 3, arr);
    ranges::sort(arr, greater());
    vector<ll> ans = {arr[2]};
    for (int i = 3; i < n; i++) {
        if (v[i] >= arr[0]) {
            arr[2] = arr[1];
            arr[1] = arr[0];
            arr[0] = v[i];
        } else if (v[i] >= arr[1]) {
            arr[2] = arr[1];
            arr[1] = v[i];
        } else if (v[i] >= arr[2]) {
            arr[2] = v[i];
        }
        ans.push_back(arr[2]);
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
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