#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int, greater<>> s;
        bool repeat{};
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (!repeat && s.count(tmp)) {
                repeat = true;
            } else {
                s.emplace(tmp);
            }
        }
        if (repeat) {
            cout << "-1";
        } else {
            for (auto i : s) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}