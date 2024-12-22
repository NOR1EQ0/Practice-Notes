#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> a;
    vector<int> b;
    vector<int> diff;
    a.reserve(100);
    b.reserve(100);
    diff.reserve(100);
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int in;
            cin >> in;
            a.push_back(in);
        }
        for (int i = 0; i < n; ++i) {
            int in;
            cin >> in;
            b.push_back(in);
        }
        for (auto i = a.begin(), j = b.begin() + 1; i != a.end() - 1; i++, j++) {
            diff.push_back(*i - *j);
        }
        diff.push_back(*(a.end() - 1));
        sort(diff.rbegin(), diff.rend());
        for (auto i : diff) {
            int tmp = ans;
            tmp += i;
            if (tmp >= ans) {
                ans = tmp;
            } else {
                break;
            }
        }
        cout << ans << '\n';
        a.clear();
        b.clear();
        diff.clear();
    }
    return 0;
}