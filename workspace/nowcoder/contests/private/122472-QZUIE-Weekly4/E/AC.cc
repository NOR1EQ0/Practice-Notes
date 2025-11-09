#include <bits/stdc++.h>

using namespace std;
using ll = long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0;
    while (n--) {
        ll tmp;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum << '\n';
}