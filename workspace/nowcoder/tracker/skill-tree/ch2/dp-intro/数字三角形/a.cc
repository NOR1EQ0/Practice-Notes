#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;

static inline ptrdiff_t rootl(ptrdiff_t i) {
    if (!i) {
        return numeric_limits<ptrdiff_t>::max();
    }
    auto lside =
}

static inline ptrdiff_t rootr(ptrdiff_t i) {
}

ll dp[505];
static inline void solve() {
    ll n;
    cin >> n;
    auto hill_size = (1 + n) * n / 2;
    vector<ll> hill(hill_size);
    dp[0] = hill[0];
    
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