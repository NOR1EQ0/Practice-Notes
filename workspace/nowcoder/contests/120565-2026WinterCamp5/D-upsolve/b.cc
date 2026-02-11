#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map<ll, ll> m;
    while (n--) {
        ll c, w;
        cin >> c >> w;
        m[w] = m[w] + c;
    }
    ll sum = 0;
    ll presum = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        
    }

    cout << sum;
}