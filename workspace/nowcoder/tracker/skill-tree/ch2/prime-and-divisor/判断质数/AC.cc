#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

bool isprime(ull val) {
    if (val == 1) {
        return false;
    }
    if (val <= 3) {
        return true;
    }
    if (!(val % 2) || !(val % 3)) {
        return false;
    }
    for (ull i = 5; i * i <= val; i += 6) {
        if (val % i == 0 || val % (i + 2) == 0) return false;
    }
    return true;
}

// #define MULTI

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
#ifdef MULTI
    int t;
    cin >> t;
    while (t--) {
#endif
        ull n;
        cin >> n;
        auto res = isprime(n);
        cout << (res ? "Yes\n" : "No\n");
#ifdef MULTI
    }
#endif
}