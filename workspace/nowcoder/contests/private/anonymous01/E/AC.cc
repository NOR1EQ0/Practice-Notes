#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string b;
        cin >> n >> b;
        string dict;
        {
            set<char> s;
            for (auto c: b) s.emplace(c);
            for (auto c: s) dict.push_back(c);
        }
        int dictlen = dict.size();
        unordered_map<char, char> m;
        for (int i = 0; i < dictlen; i++) {
            m[dict[i]] = dict[dictlen - i - 1];
        }
        string ans;
        ans.resize(n);
        for (int i = 0; i < n; i++) {
            ans[i] = m[b[i]];
        }
        cout << ans << '\n';
    }
}