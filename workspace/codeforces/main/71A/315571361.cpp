#include <bits/stdc++.h>

using namespace std;
char str[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        auto len = strlen(str);
        if (len <= 10) {
            cout << str << '\n';
            continue;
        }
        cout << str[0] << len-2 << str[len-1] << '\n';
    }

    return 0;
}