#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll sum{};
    ll a;
    for (int i = 0; i < m; i++) {
        cin >> a;
        sum += a;
    }
    if (sum == n * m) {
        cout << n << '\n';
    } else if (sum > (m - 1) * n) {
        cout << sum % n << '\n';
    } else {
        cout << "0\n";
    }
}