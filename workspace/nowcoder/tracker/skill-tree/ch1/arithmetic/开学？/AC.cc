#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x, n;
    cin >> x >> n;
    x--;
    x += n;
    x %= 7;
    x++;
    cout << x << '\n';
}