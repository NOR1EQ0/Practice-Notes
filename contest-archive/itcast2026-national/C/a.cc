#include <bits/stdc++.h>

using namespace std;
using ll = long long;
static inline void solve() {
    ll n;
    cin >> n;
    string x;
    cin >> x;

    // 3-sized slide window
    for (int i = 0; i < n - 3; i++) {
        array<string, 3> arr;
        fill(arr.begin() + 1, arr.end(), []() -> string {
            string ret;
            ret.resize(3);
            return ret;
        }());
        arr[0] = x.substr(i, 3);
        int offset1[] = {2, 3, 1};
        int offset2[] = {3, 1, 2};
        for (int i = 0; i < 3; i++) {
            arr[1][i] = arr[1][offset1[i] - 1];
            arr[2][i] = arr[2][offset2[i] - 2];
        }
        sort(arr.begin(), arr.end());
    }

    bool swapflg[2]{};
    for (int i = 0; i < n - 1; i++) {
        if (x[i] < x[i + 1]) {
            swap(x[i], x[i + 1]);
            swapflg[0] = true;
            break;
        }
    }
    if (swapflg[0] == false) {
        cout << x << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (x[i] < x[i + 1]) {
            swapflg[1] = true;
            swap(x[i], x[i + 1]);
            break;
        }
    }
    if (swapflg[1] == false) {
        swap(x[0], x[1]);
    }
    cout << x << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}