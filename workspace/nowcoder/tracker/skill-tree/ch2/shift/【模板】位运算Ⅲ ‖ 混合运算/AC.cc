#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll o, x, p;
        cin >> o >> x >> p;
        if (o == 1) {
            constexpr ll mask = ~0xfff;
            ll tmp = x << p;
            tmp |= mask;
            tmp ^= mask;
            cout << tmp;
        } else if (o == 2) {
            ll tmp = ((1 << p) - 1) << (12 - p);
            tmp = tmp | (x >> p);
            cout << tmp;
        } else if (o == 3) {
            ll tmp = (1 << p);
            if (tmp & x) {
                cout << (x - tmp);
            } else {
                cout << x;
            }
        } else if (o == 4) {
            ll tmp = (1 << p);
            cout << (x | tmp);
        }
        cout << '\n';
    }
}