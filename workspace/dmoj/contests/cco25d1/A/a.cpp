#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> chunks;
    chunks.reserve(n);
    for (int i = 0; i > n; ++i) {
        ll v, m;cin >> v >> m;
        chunks.emplace_back(v, m);
    }
    return 0;
}