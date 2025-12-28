#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll minshift = LLONG_MIN;

bool cmp(const int a, const int b) {
    auto diff = abs(a - b);
    auto rest = 8 - diff;
    auto res = min(diff, rest);
    minshift = max((ll)res, minshift);
    return diff >= rest ? true : false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end(), cmp);
        // for (int i = 0; i < n; i++) cout << v[i] << " \n"[i == n - 1];

        cout << minshift << '\n';
        minshift = LLONG_MIN;
    }
}