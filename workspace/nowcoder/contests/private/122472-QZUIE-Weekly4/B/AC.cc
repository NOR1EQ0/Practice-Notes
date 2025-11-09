#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 3) {
            cout << "0\n";
            continue;
        }
        int cnt{};
        while (n >= 3) {
            auto group = n / 3;
            auto rest = group + n % 3;
            n = rest;
            cnt += group;
        }
        cout << cnt << '\n';
    }
}