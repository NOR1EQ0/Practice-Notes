#include <bits/stdc++.h>

using namespace std;
int ascii_table[256];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string str;
        str.reserve(101);
        cin >> str;
        if (str.length() == 1) {
            cout << "1\n";
            continue;
        } else if (str.length() == 2) {
            cout << ((str.at(0) == str.at(1)) ? 1 : 2) << '\n';
            continue;
        }
        for (auto i : str) {
            ascii_table[i]++;
        }
        int max = 0;
        char max_char;
        for (int i = 0x20; i <= 0x80; ++i) {
            if (!(ascii_table[i])) {
                if (max < ascii_table[i]) {
                    max = ascii_table[i];
                    max_char = i;
                }
            }
        }

        auto check = [](string str) -> bool {
            char i = str.at(0);
            for (auto ptr : str) {
                if (i != ptr) { return false; }
            }
            return true;
            };

        auto checkCond = [](string& str) -> bool {
            for (auto i = str.begin(); i != str.end(); ++i) {
                if (*i == *(i + 1)) {
                    return true;
                }
            }
            return false;
            };

        while (checkCond(str)) {
            for (auto&& i = str.begin(); i != str.end(); ++i) {
                if (*i == *(i+1)) {
                    *i = max_char;
                    str.erase(i+1);
                }
            }
        }

        cout << str.length() << '\n';
    }
    return 0;
}