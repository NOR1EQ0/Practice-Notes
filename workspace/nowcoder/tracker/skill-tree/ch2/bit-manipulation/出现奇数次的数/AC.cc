#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    n = 2 * n + 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        res ^= tmp;
    }
    cout << res << '\n';
}