#include <bits/stdc++.h>

using namespace std;
char str[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> str;
        char* ptr = str + strlen(str) - 1;
        for (;ptr >= str;--ptr) {
            if (*ptr == 'u') {
                if (*(ptr + 1) == 's')
                    break;
            }
        }
        for (char* i = str; i < ptr; ++i) { cout << *i; }
        cout << "i\n";
    }
    return 0;
}