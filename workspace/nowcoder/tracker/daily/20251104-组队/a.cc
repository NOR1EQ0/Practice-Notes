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

        auto maxnum = v.back(), curnum = v.front();

        // Max of selected;
        size_t melected{};

        // 1 3 5 6 8
        // 3 5 6

        auto last = v.begin();

        while (1) {
            auto it = upper_bound(last, v.end(), curnum + 3);
            if (it != v.begin()) {
                it--;
            }

            auto diff = it - last;
            melected = max(melected, (size_t)diff);
        }

        v.clear();
    }
}