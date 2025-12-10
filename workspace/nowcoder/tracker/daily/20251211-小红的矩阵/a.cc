#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    auto* v = new int[n * m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i * m + j] = (i + 1) * (j + 1);
        }
    }
    sort(v, v + n * m);
    cout << v[k - 1] << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << v[i * m + j] << " \n"[j == m - 1];
    //     }
    // }
}