#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    a %= 100, b %= 100;
    int c = (a + b) % 100;
    cout << c << '\n';
}