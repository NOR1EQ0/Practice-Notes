#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bool ba = (c == a * b), bb = (c == a + b);
        if (ba) {
            cout << "Lv Yan";
        }else
        if (bb) {
            cout << "Tu Dou";
        }
        if (!ba && !bb) {
            cout << "zhe du shi sha ya!";
        }
        cout << '\n';
    }
}