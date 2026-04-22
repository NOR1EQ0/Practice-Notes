#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    ll q;
    cin >> q;
    while (q--) {
        ll m;
        cin >> m;
        auto it = upper_bound(v.begin(), v.end(), m);
        cout << it - v.begin() << '\n';
    }
}