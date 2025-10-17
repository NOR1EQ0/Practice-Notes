#include <bits/stdc++.h>

using namespace  std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    using ul = size_t;
    ul t;cin>>t;
    while (t--) {
        ul n;cin>>n;
        ul mmax = numeric_limits<ul>::min();
        while (n--) {
            ul tmp;
            cin >> tmp;
            mmax = max(tmp, mmax);
        }
        cout << mmax << '\n';
    }
}