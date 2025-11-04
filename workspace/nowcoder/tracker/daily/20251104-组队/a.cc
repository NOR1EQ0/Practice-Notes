#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<ll> v;
    v.reserve(2e5);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        v.resize(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        auto maxnum = v.front(), minnum = v.back();

        size_t melected{};

        auto it = v.begin();
        // lower_bound()

        v.clear();
    }
}