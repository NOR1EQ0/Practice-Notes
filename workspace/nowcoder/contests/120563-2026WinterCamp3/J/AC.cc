#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ull n, q;
        cin >> n >> q;
        while (q--) {
            ull x;
            cin >> x;
            ull lzero = __builtin_clzll(x);
            ull lbound = 1ull << (63ull - lzero);
            ull ubound = min((~ull()) >> (lzero), n);
            cout << ubound - lbound + 1 << '\n';
        }
    }
}