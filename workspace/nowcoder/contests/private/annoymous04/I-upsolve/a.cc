#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(1);
    vector<int> b;
    a.reserve(n);
    b.reserve(n);
    int tower_cnt{}, highest{1};
    cin >> a[0];
    n--;
    while (n--) {
        int c;
        cin >> c;
        if (c < a.back()) {
            a.push_back(c);
            highest = max((int)a.size(), highest);
        } else {
            b.push_back(c);
            if (!b.empty()) {
                tower_cnt++;
                highest = max((int)a.size(), highest);
                a = b;
                b.clear();
            }
        }
    }
    cout << tower_cnt << ' ' << highest << '\n';
}