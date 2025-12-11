#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        long cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n; ) {
            long thiscnt = 0;
            int j = i + 1;
            for (; j < n; j++) {
                if (v[i] > v[j]) thiscnt++;
                else break;
            }
            i = j, cnt += thiscnt;
        }
        cout << cnt << '\n';
    }
}