#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
// int dp[1005][1005];
static inline void solve() {
    // memset(dp,0,sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    // vector<int> dp(n+1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0]=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j]=dp[i-1][j];
            if (j>=v[i-1]){
                dp[i][j]= dp[i][j] || dp[i-1][j-v[i-1]];
            }
        }
    }
    cout << (dp[n][k] ? "Yes\n" : "No\n");
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