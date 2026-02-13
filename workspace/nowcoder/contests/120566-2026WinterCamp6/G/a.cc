#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> stpresum(n);
    vector<int> feetv(m);
    cin >> stpresum.front();
    for (int i = 1; i < n; i++) {
        int tmp;
        cin >> tmp;
        stpresum[i] += stpresum[i-1];
    }
    for (auto& i : feetv) cin >> i;
    int backpos = 0;
    for (auto i : feetv) {
        backpos += i;
        auto frontpos = backpos + l;
    }
}