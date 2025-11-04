#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    map<ll, size_t> m;
    vector<int> v;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (ll i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            m[tmp]++;
        }

        size_t msel{};
        auto l = m.begin();
        size_t curcnt{};
        
        for (auto r = m.begin(); r != m.end(); r++) {
            curcnt += r->second;

            while (r->first - l->first > k) {
                curcnt -= l->second;
                l++;
            }

            msel = max(curcnt, msel);
        }

        cout << msel << '\n';

        m.clear();
    }
}