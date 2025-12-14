#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    double aa, bb, cc;
    cin >> aa >> bb >> cc;
    ll a = (ll)(aa * 1e6 + 0.5),
       b = (ll)(bb * 1e6 + 0.5),
       c = (ll)(cc * 1e6 + 0.5);
    cout << (a - b == c ? "YES\n" : "NO\n");
}