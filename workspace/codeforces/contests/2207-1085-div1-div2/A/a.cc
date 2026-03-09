#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n;
    cin >> t;
    string s;
    string ls;
    const string pa1 = "101",
                 pa2 = "111";

    while (t--) {
        cin >> n >> s;
        ls = s;
        int lol{};
        int lll{};
        int lpidx = -1;
        for (int i = 0; i <= n - 3; i++) {
            if (s[i] == '1' && s[i + 2] == '1') {
                s[i + 1] = '0';
            }
            if (ls[i] == '1' && ls[i + 2] == '1') {
                ls[i + 1] = '1';
            }
        }
        int mincnt = count(s.begin(), s.end(), '1');
        int maxcnt = count(ls.begin(), ls.end(), '1');
        cout << mincnt << ' ' << maxcnt << '\n';
    }
}