#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    double r1, r2;
    cin >> r1 >> r2;
    cout << fixed << setprecision(3) << (1 / (1 / r1 + 1 / r2)) << '\n';
}
