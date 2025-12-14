#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int nmin, nmax;
    cin >> nmin;
    nmax = nmin;
    int x;
    cin >> x;
    nmin = min(nmin, x), nmax = max(nmax, x);
    cin >> x;
    nmin = min(nmin, x), nmax = max(nmax, x);
    cout << "The maximum number is : " << nmax << "\n"
                                                  "The minimum number is : "
         << nmin << '\n';
}