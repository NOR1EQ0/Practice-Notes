#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        ll ops = 0;
        while ((x & y) != x) {
            x >>= 1;
            ops++;
        }
        if (x != y) ops++;
        cout << ops << '\n';
    }
}