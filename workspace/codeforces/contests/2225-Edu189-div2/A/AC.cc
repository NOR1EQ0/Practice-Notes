#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        bool exist = false;
        ll single = x;
        for (ll i = x * 2; i < y; i += single) {
            if (y % i != 0) {
                exist = true;
                break;
            }
        }
        if (exist) {
            cout << "YES\n"sv;
        } else {
            cout << "NO\n"sv;
        }
    }
}