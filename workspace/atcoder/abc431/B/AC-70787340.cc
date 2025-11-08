#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x, n;
    cin >> x >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    unordered_set<size_t> us;
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        size_t p;
        cin >> p;
        p--;
        if (us.find(p) != us.end()) {
            x -= w[p];
            us.erase(p);
        } else {
            x += w[p];
            us.emplace(p);
        }
        cout << x << '\n';
    }
}