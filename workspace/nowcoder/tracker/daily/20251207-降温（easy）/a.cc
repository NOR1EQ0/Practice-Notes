#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr auto invalid = -999;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> minv = v;

    if (v[0] == invalid) v[0] = 50;
    for (int i = 1; i < n; i++) {
        int tmp;
        if (v[i] == invalid) {
            auto tmpnum = v[i - 1] - x;
            if (tmpnum < -50) {
                v[i] = 50;
            } else {
                v[i] = tmpnum;
            }
        }
    }

    for (auto i: v) cout << i << ' ';

    // ll unknown_cnt = 0l;
    // for (int i = 0; i < n; i++) {
    //     if (v[i] == invalid) {
    //         unknown_cnt++;
    //     }
    // }
}