#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int t, x;
    cin >> t >> x;t++;
    vector<int> v(t);
    for (auto& i : v) cin >> i;
    cout << "0 " << v[0] << '\n';
    int saved = v[0];
    for (int i = 1; i < t; i++) {
        int diff = abs(v[i] - saved);
        if (diff >= x) {
            cout << i << ' ' << v[i] << '\n';
            saved = v[i];
        }
    }
}