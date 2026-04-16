#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    if (n == 1) {
        ll a, b;
        cin >> a >> b;
        ll rest = a % b, divide = a / b;
        if (rest) {
            if (divide) {
                cout << divide << ' ';
            }
            cout << rest << ' ' << b << '\n';
        } else {
            cout << divide << '\n';
        }
        return 0;
    }
    ll frag1c, frag1p, frag2c, frag2p;
    char slash;
    cin >> frag1c >> slash >> frag1p;
    for (int i = 1; i < n; i++) {
        cin >> frag2c >> slash >> frag2p;
        auto fraglcm = lcm(frag1p, frag2p);
        frag1c = frag1c * (fraglcm / frag1p);
        frag2c = frag2c * (fraglcm / frag2p);
        frag1c += frag2c;
        if (frag1c % fraglcm == 0) {
            frag1c /= fraglcm;
            frag1p = 1;
        } else {
            frag1p = fraglcm;
            auto fraggcd = gcd(frag1c, frag1p);
            frag1c /= fraggcd;
            frag1p /= fraggcd;
        }
    }
    ll divide = frag1c / frag1p, rest = frag1c % frag1p;
    if (rest) {
        if (divide) {
            cout << divide << ' ';
        }
        cout << rest << '/' << frag1p;
    } else {
        cout << divide;
    }
    cout << '\n';
}