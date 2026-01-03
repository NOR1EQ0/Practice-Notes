#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ull n;
    cin >> n;
    cout << ((1 << n) - 2 * n) << '\n';
}