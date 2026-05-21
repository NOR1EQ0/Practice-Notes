#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline char xor01(char x, char y) {
    return '0' + (x != y);
}
static inline void solve() {
    string in;
    cin >> in;
    ll n = in.size();
    auto cmp_max = [](string& lhs, string& rhs) -> bool {
        if (lhs.length() != rhs.length()) {
            return lhs.length() < rhs.length();
        } else {
            return lhs < rhs;
        }
    };
    string arr[3];
    {
        arr[0] = in.substr(2);
        arr[0].back() = xor01(arr[0].back(), in[0]);
    }
    if (n > 3) {
        arr[1] = '0' + in.substr(3);
        arr[1].back() = xor01(arr[1].back(), in[1]);
        arr[1][arr[1].length() - 2] = xor01(arr[1][arr[1].length() - 2], in[0]);
    }
    if (n > 4) {
        arr[2] = in.substr(0, n - 2);
        arr[2].back() = xor01(arr[2].back(), in.back());
    }
    for (auto& s : arr) {
        auto first1 = s.find_first_of('1');
        if (first1 != string::npos) {
            s.erase(0, first1);
        } else {
            s = "0"sv;
        }
    }
    auto& ans = *ranges::max_element(arr, cmp_max);
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