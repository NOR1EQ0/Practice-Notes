#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    uint32_t n;
    cin >> n;
    cout << ((n << 16) | (n >> 16)) << '\n';
}