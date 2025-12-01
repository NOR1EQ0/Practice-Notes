#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e3 + 5;
struct student {
    int id, total;
} a[MAXN];

int cmp(student a, student b) {
    if (a.total != b.total) return a.total > b.total;
    else
        return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map<int, vector<int>> cmap;
    vector<bool> committed(n + 1);
    committed.front() = 1;
    for (int i = 0; i < k; i++) {
        int c, p, score;
        cin >> c >> p >> score;
        if (cmap.find(c) == cmap.end()) {
            cmap[c].resize(m);
        }
        cmap[c][p - 1] = max(cmap[c][p - 1], score);
        committed[c] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!committed[i]) cmap[i];
    }

    set<int> AKIndexes;

    {
        int pos{};
        for (auto& p : cmap) {
            auto& vref = p.second;
            auto totalscore = accumulate(vref.begin(), vref.end(), 0);
            if (totalscore == m * 100) AKIndexes.emplace(p.first);
            a[pos] = {p.first, totalscore};
            pos++;
        }
    }

    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << a[i].id << ' ' << a[i].total << ' ';
        auto thisit = cmap.find(a[i].id);
        if (thisit != cmap.end() && !(thisit->second.empty())) {
            for (int j = 0; j < m; j++) {
                // cout << "REACH " << flush;
                cout << cmap[a[i].id][j] << " \n"[j == m - 1];
            }
        } else {
            for (int j = 0; j < m; j++) {
                cout << '0' << " \n"[j == m - 1];
            }
        }
    }

    for (auto i : AKIndexes) {
        cout << i << ' ';
    }
    cout << '\n';
}