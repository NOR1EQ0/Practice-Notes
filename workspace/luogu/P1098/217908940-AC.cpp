#include <bits/stdc++.h>

using namespace std;
string str;

bool isRequired(size_t index) {
    if (index == 0 || index == str.length() - 1) return false;
    if ((islower(str[index - 1]) && islower(str[index + 1]))
        ||
        (isdigit(str[index - 1]) && isdigit(str[index + 1]))
        ) {
        if (str[index + 1] > str[index - 1]) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int params[3];
    cin
        >> params[0]    // Letter: 1 Lower / 2 Upper
        >> params[1]    // Repeat times (1 - 8)
        >> params[2];   // Direction: 1 Original / 2 Reverse
    str.reserve(100); cin >> str; auto len = str.length();
    size_t last = 0;
    last = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] != '-'
            ||
            !isRequired(i)) {
            cout << str[i];
            continue;
        }
        char sides[2] = { str[i - 1] + (char)1, str[i + 1] - (char)1 };
        if (params[0] != 3) {
            for (char start = params[2] == 1 ? sides[0] : sides[1];
                (params[2] == 1 ? start <= sides[1] : start >= sides[0]);
                params[2] == 1 ? start++ : start--) {
                for (size_t i = 0; i < params[1]; ++i) {
                    cout << static_cast<char>(params[0] == 2 ? toupper(start) : tolower(start));
                }
            }
        } else {
            size_t dis = abs(static_cast<int>(sides[1]) - static_cast<int>(sides[0]) + 1);
            for (size_t i = 0; i < dis; ++i)
                for (size_t j = 0; j < params[1]; ++j)
                    cout << '*';
        }
    }
    cout.put('\n');
    return 0; 
}