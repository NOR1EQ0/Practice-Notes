#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;
        vector<int> v;
        v.reserve(n);
        while (n--) {
            int tmp;
            cin >> tmp;
            if (tmp <= max(h, l)) {
                v.emplace_back(tmp);
            }
        }
        sort(v.begin(), v.end());
        int mid = v.size() / 2;
        int p = 0;
        for (int i = 0; i < mid; i++) {
            if (v[i] <= min(h,l)) {
                p++;
            } else {
                break;
            }
        }
        cout << p << '\n';
    }
}