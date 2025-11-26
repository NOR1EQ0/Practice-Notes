#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll mmax = LONG_LONG_MIN + 1,
           lmax = LONG_LONG_MIN;
        for (ll i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            if (tmp > mmax) {
                lmax = mmax;
                mmax = tmp;
            } else {
                if (tmp > lmax) {
                    lmax = tmp;
                }
            }
        }
        cout << lmax * (n - 1) << '\n';
    }
}