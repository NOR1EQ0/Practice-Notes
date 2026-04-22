#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << k + (k - 1) / (n - 1) << '\n';
    }
}