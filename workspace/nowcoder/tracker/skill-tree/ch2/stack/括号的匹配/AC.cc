#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    unordered_map<char, int> rank;
    rank['{'] = 0;
    rank['['] = 1;
    rank['('] = 2;
    rank['<'] = 3;

    unordered_map<char, char> match;
    match['{'] = '}';
    match['['] = ']';
    match['('] = ')';
    match['<'] = '>';

    while (t--) {
        string s;
        cin >> s;
        vector<char> stk;
        stk.reserve(s.size());
        bool valid = true;

        for (auto c : s) {
            // Left brace
            if (c == '{' || c == '[' || c == '(' || c == '<') {
                if (!stk.empty()) {
                    if (rank[c] < rank[stk.back()]) {
                        valid = false;
                        break;
                    }
                }
                stk.push_back(c);
            } else { // Right brace
                if (stk.empty()) {
                    valid = false;
                    break;
                }
                if (c != match[stk.back()]) {
                    valid = false;
                    break;
                }
                stk.pop_back();
            }
        }

        cout << (valid && stk.empty() ? "YES\n" : "NO\n");
    }
}