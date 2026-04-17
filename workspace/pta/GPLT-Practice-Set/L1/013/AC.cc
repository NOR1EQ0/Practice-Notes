#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    ll sx = 1;
    ll sum = 1;
    for (ll i = 2; i <= n; i++) {
        sx *= i;
        sum += sx;
    }
    cout << sum;
}