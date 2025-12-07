#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    a *= n;
    a -= c * (n <= b);
    cout << a << '\n';
}