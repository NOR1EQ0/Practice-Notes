#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, j = 1;
    size_t cnt{};
    for (; j < n && i < j;) {
        auto thisnum = v[i];
        auto ilower = lower_bound(v.begin() + i, v.end(), thisnum);
        auto iupper = upper_bound(ilower, v.end(), thisnum);
        auto nextnum = thisnum + c;
        auto jlower = lower_bound(v.begin() + j, v.end(), nextnum);
        auto jupper = upper_bound(jlower, v.end(), thisnum);

        if (jlower == v.end()) {
            
        }
    }
    cout << cnt << '\n';
}