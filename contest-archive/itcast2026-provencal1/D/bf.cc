#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

// #define FASTIO
#define EXAMPLE

int main() {
#ifdef EXAMPLE
    freopen("example.txt", "rb", stdin);
#endif
#ifdef FASTIO
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        int ans = INT_MIN;
        // read
        for (int i = 0; i < n; i++) cin >> v[i];

        // brute force
        for (int i = 0; i <= n - m; i++) {
            // i -> head
            // for (int j = m; j <= n; j++) {
            //     vector<int> cp(j);
            //     copy(v.begin() + i, v.begin() + min(n, i + j), cp.begin());
            //     sort(cp.begin(), cp.end());
            //     int midn = cp[(cp.size() - 1) / 2];
            //     ans = max(midn, ans);
            // }

            for (int j = i + m; j <= n; j++) {
                vector<int> cp(j - i);
                copy(v.begin() + i, v.begin() + j, cp.begin());
                sort(cp.begin(), cp.end());
                int midn = cp[(cp.size() - 1) / 2];
                ans = max(midn, ans);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}