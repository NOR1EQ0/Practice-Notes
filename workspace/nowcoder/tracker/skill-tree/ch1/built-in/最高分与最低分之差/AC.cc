#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int nmin = INT_MAX, nmax = INT_MIN;
    while (n--) {
        int x;
        cin >> x;
        nmin = min(nmin, x), nmax = max(nmax, x);
    }
    cout << nmax - nmin << '\n';
}