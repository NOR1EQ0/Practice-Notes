#include <bits/stdc++.h>

using namespace std;
using u32 = uint32_t;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ull a, b, p;
    cin >> a >> b >> p;
    ull ans = 1;
    ull tmpb = b, tmpa = a;
    while (tmpb > 0) {
        if (tmpb & 1) {
            ans = ans * tmpa % p;
        }
        tmpa = tmpa * tmpa % p;
        tmpb >>= 1;
    }
    cout << a << '^' << b << " mod " << p << '=' << ans << '\n';
}