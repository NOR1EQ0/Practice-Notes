#include <bits/stdc++.h>

using namespace std;
constexpr auto yes = "Yes\n"sv,
               no = "No\n"sv;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int m;
    cin >> m;
    vector<string> svec(m);
    for (auto& s : svec) cin >> s;

    for (auto& s : svec) {
        if (s.length() != n) {
            cout << no;
            continue;
        }
        bool finish = true;
        for (int i = 0; i < n; i++) {
            auto spine_c = s[i];
            auto rib_len = a[i],
                 rib_needle = b[i] - 1;
            bool find = false;
            for (auto& rib : svec) {
                if (rib_len != rib.length()) {
                    continue;
                }
                if (rib[rib_needle] == spine_c) {
                    find = true;
                    break;
                }
            }
            if (!find) {
                finish = false;
                break;
            }
        }
        cout << finish ? yes : no;
    }
}