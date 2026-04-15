#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll a, b;
    cin >> a >> b;
    a = a + b;
    cout << a - 16 << '\n'
         << a - 3 << '\n'
         << a - 1 << '\n'
         << a << '\n';
}