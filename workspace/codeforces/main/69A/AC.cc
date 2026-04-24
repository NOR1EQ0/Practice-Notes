#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int x, y, z;
    x = y = z = 0;
    while (n--) {
        int tx, ty, tz;
        cin >> tx >> ty >> tz;
        x += tx;
        y += ty;
        z += tz;
    }
    if (!x && !y && !z) {
        cout << "YES\n"sv;
    } else {
        cout << "NO\n"sv;
    }
}