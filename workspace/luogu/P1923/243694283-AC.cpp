#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll n, k;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    v.reserve(n);
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end());
    cout << v[k] << '\n';
}