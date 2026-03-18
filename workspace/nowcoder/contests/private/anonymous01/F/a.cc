#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x;
        graph[x].emplace_back(y);
    }

    int queries;
    cin >> queries;
    while (queries--) {
        int q;
        cin >> q;
        auto findit = [&]() -> bool {
            
        };
    }
}