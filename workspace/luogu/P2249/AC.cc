#include <bits/stdc++.h>

using namespace std;

int* v{};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    v = new int[n+5];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        auto ptr = lower_bound(v, v + n, tmp);
        if (ptr == v + n || *ptr != tmp) {
            cout << "-1 ";
        } else {
            cout << ptr - v + 1 << ' ';
        }
    }
}