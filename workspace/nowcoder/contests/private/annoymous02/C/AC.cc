#include <bits/stdc++.h>

using namespace std;

constexpr auto butie = "Bu Tie"sv;
constexpr auto shinei = "Shi Nei"sv;
constexpr auto bure = "Bu Re"sv;
constexpr auto shushi = "Shu Shi"sv;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T, S, t;
    cin >> T >> S >> t;

    if (S) {
        if (T >= 35 and t >= 33) {
            cout << butie << '\n'
                 << T;
            return 0;
        } else if (S < 35 || t < 33) {
            cout << bure << '\n'
                 << t;
            return 0;
        }
    } else {
        if (T >= 35 and t >= 33) {
            cout << shinei << '\n'
                 << T;
            return 0;
        }
    }
    cout << shushi << '\n'
         << t;
}