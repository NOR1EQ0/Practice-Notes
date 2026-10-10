#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cout << "1 1 ";
    ll a = 1, b = 1, c;
    for (int i = 3; i <= (int)1e5; i++) {
        c = a + b;
        assert(c >= 0);
        cout << c << ' ';
        a = b;
        b = c;
    }
}