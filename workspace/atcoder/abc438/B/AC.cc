#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s, t;
    cin >> s >> t;
    if (s.find(t) != s.npos) {
        cout << "0\n";
        return 0;
    }
    size_t ops = SIZE_MAX;
    const auto tlen = t.size(), slen = s.size();
    const int ed = slen - tlen;

    for (int i = 0; i <= ed; i++) {
        size_t curr = 0;
        for (int j = 0; j < tlen; j++) {
            int tc = t[j] - '0', sc = s[i + j] - '0';
            if (tc > sc) {
                curr += (10 - tc) + sc;
            } else {
                curr += (sc - tc);
            }
        }
        ops = min(curr, ops);
    }
    assert(ops != SIZE_MAX);

    cout << ops << '\n';
}