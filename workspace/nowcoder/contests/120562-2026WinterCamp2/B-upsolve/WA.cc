#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int, greater<>> m;
        bool sameflag = true;
        cin >> v[0];
        m[v[0]] = 1;
        int max_num = v[0];
        // int max_index = 0;
        int min_num = v[0];

        for (int i = 1; i < n; i++) {
            cin >> v[i];
            m[v[i]]++;
            min_num = min(min_num, v[i]);
            max_num = max(max_num, v[i]);

            if (sameflag && v[i] != v[0]) {
                sameflag = false;
            }
        }

        if (sameflag) {
            char c = n % 2 ? '1' : '0';
            for (int i = 0; i < n; i++) cout << c;
            cout << '\n';
            continue;
        }

        bool flag = false;

        for (auto it = m.begin(); it != m.end(); it++) {
            auto v = it->second;
            if (v % 2) {
                m.erase(next(it), m.end());
                flag = true;
                break;
            }
        }

        if (flag) {
            for (auto i: v) {
                char c = m.count(i) ? '1' : '0';
                cout << c;
            }
        } else {
            for (auto i : v) {
                char c = max_num == i ? '1' : '0';
                cout << c;
            }
        }

        cout << '\n';
    }
}
