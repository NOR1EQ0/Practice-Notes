#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    string s;
    cin >> s;
    ll sum_r{}, sum_b{}, cnt_r{}, cnt_b{};
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt_r++;
            sum_r += v[i];
        } else {
            cnt_b++;
            sum_b += v[i];
        }
    }
    ll sum = sum_r + sum_b;
    if (cnt_r * sum % n) {
        cout << "-1\n";
    } else {
        cout << abs(cnt_r * sum / n - sum_r) << '\n';
    }
}
int main() {
#if defined(ONLINE_JUDGE) || 1
    ios::sync_with_stdio(0), cin.tie(0);
#elif 10
    freopen("1.in", "rb", stdin);
#endif
    ll t = 1;
    ;
    while (t--) {
        solve();
    }
}