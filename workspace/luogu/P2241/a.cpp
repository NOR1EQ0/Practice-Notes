#include <bits/stdc++.h>

using namespace std;

int main() {
    using ull = unsigned long long;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    ull sq = n*m, rect = !(n==m);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (i == j) {
                sq += (n/i) * (m/j);
                continue;
            }
            rect += (n/i) * (m/j);
        }
    }
    cout << sq << ' ' << rect << '\n';
    return 0;
}