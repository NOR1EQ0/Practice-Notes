#include <bits/stdc++.h>

using namespace std;

using arr_t = int[1005][1005];
using vi_t = vector<int>;
using vec_t = vector<vi_t>;

#ifdef ONLINE_JUDGE
arr_t arr, wall, dp;
#endif

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
#ifndef ONLINE_JUDGE
    vec_t arr(n + 1, vi_t(m + 1)),
        wall(n + 1, vi_t(m + 1)),
        dp(n + 1, vi_t(m + 1));
#endif
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        wall[x][y] = v;
    }
    int posx{}, posy{};
    dp[1][1] = arr[1][1];
    int coin = dp[1][1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 and j == 1) continue;
            int currStep = i + j - 2;
            if (wall[i][j] and wall[i][j] <= currStep) continue;

            auto top = dp[i - 1][j], left = dp[i][j - 1];
            if (!top and !left) continue;

            dp[i][j] = max(top, left) + arr[i][j];
            coin = max(dp[i][j], coin);
        }
    }

    cout << coin << '\n';
}