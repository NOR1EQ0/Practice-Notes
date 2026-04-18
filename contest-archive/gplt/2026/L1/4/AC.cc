#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int rate;
        cin >> rate;
        if (rate < 1700) cnt++;
    }
    cout << cnt << '\n';
}