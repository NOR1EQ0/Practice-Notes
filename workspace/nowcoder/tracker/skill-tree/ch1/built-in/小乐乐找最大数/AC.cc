#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    int x;
    cin >> n;
    cin >> x;
    n = max(n, x);
    cin >> x;
    n = max(n, x);
    cin >> x;
    n = max(n, x);
    cout << n << '\n';
}