#include <bits/stdc++.h>

using namespace std;
using ll = long long;
static inline void solve() {
    ll n;
    cin >> n;
    string x;
    cin >> x;

    if (n == 2) {
        cout << x << '\n';
        return;
    }

    ll operation = 2;

    for (int i = 0; i < n - 2; i++) {
        auto sb = x.substr(i, 3);
        auto charcnt = [&]() {
            set<char> s;
            for (auto c : sb) {
                s.emplace(s);
            }
            return s.size();
        }();
        if (charcnt == 1) {
            continue;
        }
        if (charcnt == 2) {
            // aba type
            if (x[i] != x[i + 1] && x[i + 1] != x[i + 2]) {
                if (x[i] > x[i + 1]) {
                    swap(x[i + 1], x[i + 2]);
                } else {
                    swap(x[i], x[i + 1]);
                }
                operation--;
            }
            // aab type
            if (x[i] == x[i + 1] && x[i + 1] != x[i + 2]) {
                if (x[i + 2] > x[i]) {
                    swap(x[i], x[i + 2]);
                    operation -= 2;
                }
            }
            // abb type
            if (x[i] != x[i + 1] && x[i + 1] == x[i + 2]) {
                if (x[i + 1] > x[i]) {
                    swap(x[i], x[i + 2]);
                    operation -= 2;
                }
            }
        }
        if (charcnt == 3) {
            array<string, 3> arr;
            fill(arr.begin() + 1, arr.end(), []() -> string {
                string ret;
                ret.resize(3);
                return ret;
            }());
            arr[0] = sb;
            int offset1[] = {2, 3, 1};
            int offset2[] = {3, 1, 2};
            for (int i = 0; i < 3; i++) {
                arr[1][i] = arr[1][offset1[i] - 1];
                arr[2][i] = arr[2][offset2[i] - 2];
            }
            sort(arr.begin(), arr.end());
            if (*arr.begin() != sb) {
                copy(arr[0].begin(), arr[0].begin() + 3, x.begin() + i);
                operation -= 2;
            }
            break;
        }
    }

    if (operation == 1) {
        bool swapflg = false;
        for (int i = 0; i < n - 1; i++) {
            if (x[i] < x[i + 1]) {
                swap(x[i], x[i + 1]);
                swapflg = true;
                break;
            }
        }
        if (!swapflg) {
            swap(x[n - 1], x[n - 2]);
        }
    }

    // for (int i = 0; i < n - 3; i++) {
    //     set<char> s;
    //     array<string, 3> arr;
    //     fill(arr.begin() + 1, arr.end(), []() -> string {
    //         string ret;
    //         ret.resize(3);
    //         return ret;
    //     }());
    //     for (char c: arr[0]) {
    //         s.emplace(c);
    //     }
    //     arr[0] = x.substr(i, 3);
    //     int offset1[] = {2, 3, 1};
    //     int offset2[] = {3, 1, 2};
    //     for (int i = 0; i < 3; i++) {
    //         arr[1][i] = arr[1][offset1[i] - 1];
    //         arr[2][i] = arr[2][offset2[i] - 2];
    //     }
    //     sort(arr.begin(), arr.end());
    // }

    cout << x << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}