#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll grid[100][100];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int r = 0, c = (n - 1) >> 1;
    grid[r][c] = 1;
    for (int i = 0; i < (n * n) - 1; i++) {
        int x = (r - 1 + n) % n, y = (c + 1 + n) % n;
        if (grid[x][y] != 0) {
            x = (r + 1) % n;
            y = c;
        }
        grid[x][y] = grid[r][c] + 1;
        r = x, c = y;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " \n"[j == n - 1];
        }
    }
}