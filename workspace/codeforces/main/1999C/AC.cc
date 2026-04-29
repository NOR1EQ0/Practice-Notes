#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        vector<pii> v(n + 2);
        v[0] = {0, 0};
        v.back() = {m, m};
        n++;
        for (int i = 1; i < n; i++) {
            cin >> v[i].x >> v[i].y;
        }
        n++;
        bool ableto = false;
        for (int i = 1; i < n; i++) {
            if (v[i].x - v[i - 1].y >= s) {
                ableto = true;
                break;
            }
        }
        if(ableto) {
            cout << "YES\n"sv;
        } else {
            cout << "NO\n"sv;
        }
    }
}