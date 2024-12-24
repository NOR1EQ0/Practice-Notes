#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in;
    in.reserve(101);
    cin >> in;
    for (auto i: in) {
        i = toupper(i);
        cout << i;
    }
    putchar('\n');
    return 0;
}