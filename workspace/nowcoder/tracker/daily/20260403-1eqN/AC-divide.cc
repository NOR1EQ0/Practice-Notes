#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            cnt += i;
        }
    }

    if (n > 1) cout << n + cnt;
    else
        cout << cnt;

    cout << '\n';
}