#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int n,m;
    cin >> n >> m;
    n = n / 2 + n % 2;
    if (n >= m) cout << "Yes\n";
    else cout << "No\n";
}