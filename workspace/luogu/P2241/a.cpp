#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    ll square{}, rect{};
    ll lmin = min(n, m), lmax = max(n, m);

    // SQUARE
    for (ll i = 1; i <= lmin; i++) {
        square += ((lmin / i + lmin % i) * (lmax / i + lmax % i));
    }

    // RECTANGLE
    for (ll i = 1; i <= lmax; i++) {

    }
    cout << square << '\n';
}