#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[i] = v[min(0, i - 1)] + tmp;
    }
    while (m--) {
        int l,r;
        cin >> l >> r;
        
    }
}