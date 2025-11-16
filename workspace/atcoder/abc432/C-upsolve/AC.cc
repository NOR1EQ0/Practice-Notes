#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long bmin = 0, bmax = a[0];
    long k = y - x;
    long dsum{0};
    for (int i = 1; i < n; i++) {
        long upper = x * (a[i] - a[0]);
        // auto drest = ;
        if (upper % k) {
            cout << "-1\n";
            return 0;
        }
        long d = upper / k;
        dsum += (d);
        long rvalmin = d, rvalmax = a[i] + d;
        bmin = max(rvalmin, bmin), bmax = min(rvalmax, bmax);
        if (bmin > bmax) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << n * bmax - dsum << '\n';
}