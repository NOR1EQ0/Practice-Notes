#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ull n;
    cin >> n;
    int ones = 0;
    auto p1 = __popcount(n);
    auto p2 = __builtin_popcount(n);
    for (int i = 0; i < sizeof(ull) * CHAR_BIT; i++) {
        ull tmp = 1ull << i;
        if (tmp & n) {
            ones++;
        }
    }
    cout << p1 << p2;
    cout << ones << '\n';
}