#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a[(size_t)2e5];
ll b[(size_t)2e5];

int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while (t--) {
        int n, k;cin >> n >> k;
        ll amax = -1, amin = numeric_limits<ll>().max();
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; amax = max(amax, a[i]); amin = min(amin, a[i]);
        }
        ll sum = -1;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (b[i] != -1) {
                ll current_sum = a[i] + b[i];
                if (sum == -1) {
                    sum = a[i] + b[i];
                } else {
                    if (current_sum != sum) { valid=false; }
                }
            }
        }
        if (!valid) {
            cout << "0\n"; continue;
        }
        if (sum != -1) {
            if (sum - amin > k || sum - amax < 0) {
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            if (amax - amin > k) {
                cout << 0;
            } else {
                cout << k - (amax - amin) + 1;
            }
        }
        cout << '\n';
    }
    return 0;
}