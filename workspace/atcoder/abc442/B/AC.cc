#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int vol;
    bool play{};
    char op[2];
    cin >> vol;
    vol = 0;
    while (cin >> op) {
        if (op[0] == '1') {
            vol++;
        }
        if (op[0] == '2') {
            if (vol >= 1) vol--;
        }
        if (op[0] == '3') {
            play = !play;
        }
        cout << (vol >= 3 && play ? "Yes\n": "No\n");
    }
}