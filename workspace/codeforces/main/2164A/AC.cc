#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define ok "YES\n"
#define no "NO\n"

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    vector<ll> v;
    v.reserve(105);
    while (t--) {
        int n;
        cin >> n;
        v.resize(n);
        ll mmin = LLONG_MAX,  mmax = LLONG_MIN;
        for (int i = 0; i < n; i++) {   
            cin >> v[i];
            mmin = min(mmin, v[i]);
            mmax = max(mmax, v[i]);
        }
        ll x;
        cin >> x;
        if (x >= mmin && x <= mmax) {
            cout << ok;
        } else {
            cout << no;
        }
        v.clear();
    }
}