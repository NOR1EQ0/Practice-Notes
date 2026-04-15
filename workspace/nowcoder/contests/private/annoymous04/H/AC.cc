#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s_na, s_nb;
        cin >> s_na >> s_nb;
        ll na = stoll(s_na), nb = stoll(s_nb);
        ll sa{}, sb{};
        for (auto c : s_na) {
            sa += (c - '0');
        }
        for (auto c : s_nb) {
            sb += (c - '0');
        }
        bool biggerA = (na % sb == 0);
        bool biggerB = (nb % sa == 0);
        if (biggerA ^ biggerB) {
            if (biggerA) cout << "A\n";
            else cout << "B\n";
        } else {
            if (na > nb) {
                cout << "A\n";
            } else {
                cout << "B\n";
            }
        }
    }
}