#include <bits/stdc++.h>

using namespace std;

constexpr auto valid = "Da Jiang!!!\n"sv;
constexpr auto invalid = "Ai Ya\n"sv;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    int k;
    cin >> k;
    while (k--) {
        bool allzero = true;
        bool win = true;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num) {
                allzero = false;
                if (v[i] != num) {
                    win = false;
                }
            }
        }
        if (allzero) {
            cout << invalid;
        } else {
            if (win) {
                cout << valid;
            } else {
                cout << invalid;
            }
        }
    }
}