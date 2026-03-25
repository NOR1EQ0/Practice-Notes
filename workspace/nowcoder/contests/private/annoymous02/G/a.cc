#include <bits/stdc++.h>

using namespace std;

int arr[1005][1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map<int, pair<int, int>, greater<>> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            s[arr[i][j]] = {i, j};
        }
    }
    while (k--) {
        auto [x, y] = s.begin()->second;
        for (int i = 0; i < m; i++) {
            s.erase(arr[x][i]);
            arr[x][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            s.erase(arr[i][y]);
            arr[i][y] = 0;
        }
    }
    // for (auto [key, val] : s) {
    //     if (k <= 0) break;
    //     auto [x, y] = val;
    //     for (int i = 0; i < m; i++) {
    //         s.erase(arr[y][i]);
    //         arr[y][i] = 0;
    //     }
    //     for (int i = 0; i < n; i++) {
    //         s.erase()
    //         arr[i][x] = 0;
    //     }
    //     k--;
    // }

    for (int i = 0; i < n; i++) {
        bool zerorow = true;
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                zerorow = false;
                cout << arr[i][j];
                if (j + 1 != m)
                    cout << ' ';
            }
        }
        if (!zerorow) cout << '\n';
    }
}