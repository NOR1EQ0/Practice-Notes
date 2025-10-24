#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll rest = n;
        ll cnt{};
        while (rest > 2) {
            ll gsize = rest / 3;
            ll littlesize = rest % 3
                                ? rest % 3
                                : gsize;
            rest -= (gsize + littlesize);
            cnt += littlesize;
        }

        cout << cnt << '\n';
    }
}