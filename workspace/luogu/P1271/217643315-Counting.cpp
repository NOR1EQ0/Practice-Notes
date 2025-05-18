#include <bits/stdc++.h>

using namespace std;

int cnt[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }
    for (int i = 1; i <= n; ++i) {
        int num = cnt[i];
        for (int j = 0; j < num; ++j) {
            cout << i << ' ';
        }
    }
    return 0;
}