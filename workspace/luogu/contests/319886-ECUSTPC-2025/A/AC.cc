#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, g, s, b;
    cin >> n >> g >> s >> b;
    g *= 75, s *= 30, b *= 15;
    int sum = g + s + b;
    cout << sum * 100 / n << '\n';
}