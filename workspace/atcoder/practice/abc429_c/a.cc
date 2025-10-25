#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> v;
    v.reserve(n);
    unordered_set<ll> seen;
    v.reserve(2e5);
    ull cnt{};
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    for (ll i = 0; i < n - 2; i++) {
        ll a = v[i];
        for (ll j = i + 1; j < n - 1; j++) {
            ll b = v[j];
            auto prevflag = a == b;
            for (ll k = j + 1; k < n; k++) {
                ll c = v[k];
                if (prevflag) {
                    if (c != a) cnt++;
                } else {
                    if (c == a || c == b) cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
}