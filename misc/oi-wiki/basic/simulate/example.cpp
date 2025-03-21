#include <bits/stdc++.h>

using namespace std;
int a, b, h, pos, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> h;
    while (pos < h) {
        pos += (a - b);
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}