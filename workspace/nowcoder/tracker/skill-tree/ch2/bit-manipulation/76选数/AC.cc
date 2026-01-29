#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ull n;
    cin >> n;
    int bit_width = 64;
    for (int i = 0; i < sizeof(ull) * CHAR_BIT; i++) {
        ull tmp = 1ull << (63 - i);
        if (tmp & n) {
            break;
        } else {
            bit_width--;
        }
    }
    ull res = (1ull << bit_width) - 1;
    cout << res << '\n';
}