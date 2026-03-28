#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int z = gcd(x, y);
        if (x + y > z && x + z > y && y + z > x) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}