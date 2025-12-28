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

        sort(v.begin(), v.end());
        ans = v[(v.size() - 1) / 2];

        cout << ans << '\n';
    }
    return 0;
}