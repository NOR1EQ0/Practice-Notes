#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;cin >> n >> k;
    int cnt = 0;
    while (n--) {
        int tmp;
        cin >> tmp;
        if (tmp % k == 0) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}