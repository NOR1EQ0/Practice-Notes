#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        m.emplace(a, i);
    }
    n = 3;
    auto p = m.begin();
    while (n--) {
        cout << p->second << " \n"[!n];
        p++;
    }
}