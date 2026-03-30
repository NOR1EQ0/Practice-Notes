#include <bits/stdc++.h>

using namespace std;
constexpr auto MOD = 998244353;
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& i : a) cin >> i;
        int mn = INT_MAX;
        for (auto& i : b) {
            cin >> i;
            mn = min(i, mn);
        }
        int x = count_if(a.begin(), a.end(), [mn](int val) { return val > mn; });
        int y = n - x;
        long long ans = 1; // MUST BE 64BIT OR BE REJECTED ON ANOTHER 85% TESTCASES!!!
        for (int i = 1; i <= x; i++) {
            ans = (ans * i) % MOD;
        }
        for (int i = 1; i <= y; i++) {
            ans = (ans * i) % MOD;
        }
        cout << ans << '\n';
    }
}