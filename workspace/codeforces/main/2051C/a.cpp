#include <bits/stdc++.h>
#define max (int)(10e5*3)
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, in;
    vector<int> a, q;
    a.reserve(max);
    q.reserve(max);
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < m; i++) {
            cin >> in;
            a.push_back(in);
        } for (int i = 0; i < k; ++i) {
            cin >> in;
            q.push_back(in);
        }
        for (auto i : a) {
            for (auto j : q) {
                if (j == i || find(a.begin(), a.end(), j) == a.end()) {
                    cout << 0;
                    break;
                } else {
                    cout << 1;
                    break;
                }
            }
        }
        a.clear();
        q.clear();
        cout << '\n';
    }
    return 0;
}