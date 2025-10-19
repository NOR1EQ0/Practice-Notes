#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string& s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r == s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    using ul = size_t;
    ul t, n;
    cin >> t;
    string s;
    s.reserve(11);
    while (t--) {
        cin >> n >> s;
        bool found = false;
        vector<int> indices;
        string p, x;
        p.reserve(20), x.reserve(20);
        indices.reserve((1 << 10) + 1);
        for (ul mask = 0; mask < (1 << n); mask++) {
            for (ul i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    p += s[i];
                    indices.emplace_back(i+1);
                } else {
                    x += s[i];
                }
            }

            bool ok = true;
            for (int i = 0; i < p.size(); i++) {
                
            }

            p.clear(), x.clear();
        }
    }
}