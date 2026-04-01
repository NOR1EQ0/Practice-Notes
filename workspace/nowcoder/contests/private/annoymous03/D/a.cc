#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    ll sum{};
    while (m--) {
        ll a;
        cin >> a;
        sum += a;
    }
    cout << sum % n << '\n';
}