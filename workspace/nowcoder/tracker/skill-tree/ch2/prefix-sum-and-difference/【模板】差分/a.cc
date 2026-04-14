#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto& i : v) cin >> i;
    vector<ll> diff(n);
    adjacent_difference(v.begin(), v.end(), diff.begin());
    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        for (int i = l; i <= r; i++) {
            v[i] += d;
        }
    }
    for (auto i: v) {
        cout << i << ' ';
    }
}