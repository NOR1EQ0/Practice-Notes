#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n;
    int rights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char checksum[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    bool allpass = true;
    while (n--) {
        cin >> s;
        bool alpha_id = false;
        int z = 0;
        for (int i = 0; i < 17; i++) {
            if (!isdigit(s[i])) {
                alpha_id = true;
                allpass = false;
                break;
            }
            int digit = s[i] - '0';
            digit = digit * (rights[i] * 10) / 10;
            z += digit;
        }
        if (alpha_id) {
            cout << s << '\n';
            continue;
        } else {
            z %= 11;
            auto mapped = checksum[z];
            if (mapped != s.back()) {
                cout << s << '\n';
                continue;
            }
        }
    }
    if (allpass) {
        cout << "All passed\n"sv;
    }
}