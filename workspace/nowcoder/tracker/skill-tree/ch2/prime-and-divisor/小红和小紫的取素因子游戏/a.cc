#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr auto kou = "kou\n"sv,
               yuka = "yukari\n"sv;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ll sum{};
        for (ll i = 2ll; i * i <= x; i++) {
            while (x % i == 0) {
                sum++;
                x /= i;
            }
        }
        if (x > 1) sum++;
        cout << (sum % 2 ? kou : yuka);
    }
}