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

        ll idx = 1;
        for (idx = 1; idx < va.size(); idx++) {
            if (va[idx] < va[idx-1]) {
                break;
            }
        }
    }
}