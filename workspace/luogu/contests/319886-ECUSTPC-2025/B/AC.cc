#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int l, m2, m3;
    cin >> l >> m2 >> m3;
    for (int i = l; i < l + 6; i++) {
        int mm2 = i % 2, mm3 = i % 3;
        if (m2 == mm2 and m3 == mm3) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}