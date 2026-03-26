#include <bits/stdc++.h>

using namespace std;

constexpr auto angry = "kou is angry\n"sv;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    map<int, int> m;
    vector<array<int, 2>> v(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k >> v[i][0];
        m[v[i][0]]++;
        if (k == 1) {
            v[i][1] = 0;
        } else {
            cin >> v[i][1];
            m[v[i][1]]++;
        }
    }

    if (m.size() < n) {
        cout << angry;
        return 0;
    }

    vector<int> seq;
    seq.reserve(n);

    bool able2 = true;

    for (auto [a, b] : v) {
        auto acnt = m.count(a), bcnt = (b ? m.count(b) : size_t(0));
        if (acnt < 0 || bcnt < 0) {
            able2 = false;
            break;
        }
        if (acnt < bcnt) {
            m.erase(a);
            seq.emplace_back(a);
            if (bcnt) {
                m[b]--;
            }
        } else {
            if (bcnt) {
                m.erase(b);
                if (acnt) m[a]--;
                seq.emplace_back(b);
            } else {
                m.erase(a);
                if (bcnt) m[b]--;
                seq.emplace_back(a);
            }
        }
    }
    for (auto i : seq) {
        cout << i << ' ';
    }
}