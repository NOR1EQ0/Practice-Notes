#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    vector<ll> v;
    v.reserve(2e5);
    while (t--) {
        int n;
        cin >> n;
        v.resize(n);
        bool haseven{}, hasodd{};
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            haseven |= !(v[i] % 2), hasodd |= (v[i] % 2);
        }

        if (!(haseven ^ hasodd)) {
            sort(v.begin(), v.end());
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << " \n"[i == n - 1];
        }
    }
}