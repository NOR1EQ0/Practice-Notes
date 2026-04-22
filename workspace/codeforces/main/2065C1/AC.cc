#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> va(n);
        for (auto& i : va) cin >> i;
        cin >> m;
        va[0] = min(va[0], m - va[0]);

        bool legal = true;
        for (ll i = 1; i < n; i++) {
            ll mn = min(va[i], m - va[i]);
            if (mn >= va[i - 1]) {
                va[i] = mn;
            } else {
                ll mx = max(va[i], m - va[i]);
                if (mx < va[i]) {
                    legal = false;
                    break;
                } else {
                    va[i] = mx;
                }
            }
        }
        
        if (!legal) {
            cout << "NO\n"sv;
        } else {
            if (is_sorted(va.begin(), va.end())) {
                cout << "YES\n"sv;
            } else {
                cout << "NO\n"sv;
            }
        }
    }
}