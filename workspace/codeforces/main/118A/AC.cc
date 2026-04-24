#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    string out;
    cin >> s;
    char arr[] = "aoyeui";
    for (auto c: s) {
        c = tolower(c);
        bool is_vowel{};
        for (int i = 0; i < 6; i++) {
            if (c == arr[i]) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            out.push_back(c);
        }
    }
    for (auto c: out) {
        cout << '.' << c;
    }
}