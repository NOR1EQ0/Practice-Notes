#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < min(n, m); i++) {
        cout << "OK\n";
    }
    for (ll i = m; i < n; i++) {
        cout << "Too Many Requests\n";
    }
}