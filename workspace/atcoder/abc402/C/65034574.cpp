#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;cin >> n >> m;
    int goods=0;
    unordered_map<int, unordered_set<int>> m1;
    for (int i = 0; i < m; ++i) {
        int k; cin >> k; for (int j = 0; j < k; ++j) {
            int tmp; cin >> tmp; m1[i].emplace(tmp);
        }
    }
    for (int i = 0;i < n;++i) {
        int tmp;cin >> tmp;
        vector<int> del;
        for (auto &item: m1) {
            item.second.erase(tmp);
            if (item.second.empty()) {del.emplace_back(item.first);goods++;}
        }
        for (auto &i: del) {
            m1.erase(i);
        }
        cout << goods << '\n';
    }
    
    return 0;
}