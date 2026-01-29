#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m, n;
    cin >> m >> n;
    auto res = m ^ n;
    int bits = 0;
    for (int i = 0; i < sizeof(int) * CHAR_BIT; i++) {
        int tmp = 1 << i;
        if (res & tmp) bits++;
    }
    cout << bits << '\n';
}