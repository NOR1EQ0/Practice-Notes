#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int solve = 0;
    while (n--) {
        int sols[3];
        for (int i = 0; i < 3; ++i) {
            cin >> sols[i];
        }
        int one = 0;
        for (int i = 0; i < 3; ++i) {
            if (sols[i] == 1) one++;
            if (one >= 2) {solve++;break;}
        }
    }
    cout << solve << '\n';
    return 0;
}