#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (auto& i : v) cin >> i;
        for (ll x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}) {
            bool ok{};
            for (auto i : v) {
                if (i % x) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                cout << x << '\n';
                break;
            }
        }
    }
}