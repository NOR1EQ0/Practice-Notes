#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a[(size_t)2e5 + 10];
ll b[(size_t)2e5 + 10];

int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll amax = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > amax) amax = a[i];
        }
        ll sum = -1;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (b[i] != -1) {
                ll current_sum = a[i] + b[i];
                if (sum == -1) {
                    sum = current_sum;
                } else {
                    if (current_sum != sum) {
                        valid = false;
                    }
                }
            }
        }
        if (!valid) {
            cout << "0\n";
            continue;
        }
        if (sum != -1) {
            ll min_a_plus_k = a[0] + k;
            for (int i = 1; i < n; ++i) {
                if (a[i] + k < min_a_plus_k) {
                    min_a_plus_k = a[i] + k;
                }
            }
            if (sum < amax || sum > min_a_plus_k) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        } else {
            ll max_a = amax;
            ll min_a_plus_k = a[0] + k;
            for (int i = 1; i < n; ++i) {
                if (a[i] + k < min_a_plus_k) {
                    min_a_plus_k = a[i] + k;
                }
            }
            if (max_a > min_a_plus_k) {
                cout << "0\n";
            } else {
                cout << (min_a_plus_k - max_a + 1) << '\n';
            }
        }
    }
    return 0;
}