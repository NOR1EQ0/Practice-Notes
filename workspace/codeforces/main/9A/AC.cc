#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int y, w;
    cin >> y >> w;
    auto rest = 6 - max(y, w) + 1;
    auto lcmn = gcd(rest, 6);
    cout << rest / lcmn << '/' << 6 / lcmn << '\n';
}