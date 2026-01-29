#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        cout << (x | y) << ' ' << (x & y) << ' ' << (x ^ y) << '\n';
    }
}