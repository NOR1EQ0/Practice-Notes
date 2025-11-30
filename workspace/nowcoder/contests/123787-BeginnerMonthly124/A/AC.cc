#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long x, y;
        cin >> x >> y;
        auto minusx = x < 0 ? -1 : 1;
        auto minusy = y < 0 ? -1 : 1;
        x += minusx, y += minusy;
        cout << x << ' ' << y << '\n';
    }
}