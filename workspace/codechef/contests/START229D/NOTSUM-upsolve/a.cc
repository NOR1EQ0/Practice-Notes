#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multimap<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            mp.emplace(tmp, i);
        }
        bool find = false;
        for (auto it = mp.rbegin(); it != prev(mp.rend(), 2); it++) {
            int av = it->first, ai = it->second,
                bv = next(it, 1)->first, bi = next(it, 1)->second,
                cv = next(it, 2)->first, ci = next(it, 2)->second;
            if (av + bv != cv) {
                cout << ai << ' ' << bi << ' ' << ci << '\n';
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "-1\n";
        }
    }
}