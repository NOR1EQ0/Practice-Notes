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
    size_t ccsym[3];
    size_t last = 0;
    for (int i = 0; i < 3; ++i) {
        ccsym[i] = str.find('-', last);
        last = ccsym[i] + 1;
    }
    last = 0;
    for (int i = 0; i < 3; ++i) {
        const auto& cursym = ccsym[i];
        auto ret = isRequired(cursym);
        for (int i = last; i < cursym - 1; ++i) {
            cout << str[i];
        }
        last = cursym + 2;
        cout << str[cursym - 1];
        if (ret == false) {
            cout << str.substr(cursym, 2);
            continue;
        }
        char sides[2] = { str[cursym - 1] + 1, str[cursym + 1] - 1 };
        for (char start = params[2] == 1 ? sides[0] : sides[1];
            (params[2] == 1 ? start <= sides[1] : start >= sides[0]);
            params[2] == 1 ? start++ : start--) {
            for (size_t i = 0; i < params[1]; ++i) {
                cout << static_cast<char>(params[0] == 2 ? toupper(start) : tolower(start));
            }
        }
        cout << str[cursym + 1];
    }
    for (auto i = last; i < len; ++i) {
        cout << str[i];
    }
    cout.put('\n');
    return 0; // aCCCBBBd-d
}