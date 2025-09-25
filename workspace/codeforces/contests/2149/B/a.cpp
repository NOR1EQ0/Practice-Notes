#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v;
        while (n--) {
            ll tmp;
            cin >> tmp;
            v.emplace_back(tmp);
        }
        sort(v.begin(), v.end());
        const auto len = v.size();
        ll diff = 0;
        for (int i = 0; i < len; i += 2) {
            auto d = v[i + 1] - v[i];
            diff = max(d, diff);
        }
        cout << diff << '\n';
    }

    return 0;
}