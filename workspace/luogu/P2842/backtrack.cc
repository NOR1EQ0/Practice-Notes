#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

vector<ll> v;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    v.reserve(1e3);
    ll n, w;
    cin >> n >> w;
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end(), greater());
}