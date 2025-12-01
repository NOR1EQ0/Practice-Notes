#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater());
    auto val = a[k-1];
    long cnt{};
    for (int i = 0; i < n; i++) {
        auto arg = a[i];
        if (arg > 0 && arg >= val) {
            cnt++;
        } else break;
    }
    cout << cnt << '\n';
}