#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    bool is_conn = s.front() == s.back();
    size_t maxsublen{};
    if (is_conn) {
        size_t tailpos = s.size() - 1;
        for (; tailpos >= 0; tailpos--) {
            if (tailpos <= 0 || s[tailpos] != s[tailpos - 1]) {
                break;
            }
        }

        if (tailpos <= 1) {
            cout << s.size() << '\n';
            return 0;
        }

        auto taillen = s.size() - tailpos;

        size_t head_rbound = 0;
        for (; head_rbound < s.size() - 1; head_rbound++) {
            if (s[head_rbound] != s[head_rbound + 1]) {
                break;
            }
        }
        head_rbound++;
        auto headlen = head_rbound;

        maxsublen = max(maxsublen, taillen + headlen);

        char curr = s[head_rbound];
        size_t currlen = 0;
        for (int i = head_rbound; i < tailpos; i++) {
            if (curr != s[i]) {
                maxsublen = max(currlen, maxsublen);
                currlen = 1;
                curr = s[i];
            } else {
                currlen++;
            }
        }
        maxsublen = max(currlen, maxsublen);
    } else {
        const auto len = s.size();
        char curr = s[0];
        size_t currlen = 0;
        for (int i = 0; i < len; i++) {
            if (curr != s[i]) {
                maxsublen = max(currlen, maxsublen);
                currlen = 1;
                curr = s[i];
            } else {
                currlen++;
            }
        }
        maxsublen = max(currlen, maxsublen);
    }

    cout << maxsublen << '\n';
}