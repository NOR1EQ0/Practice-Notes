#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char in;
    int ops = 0;
    while ((in = cin.get()) != '\n' && in != EOF) {
        if (in == ' ') {
            ops++;
            continue;
        }
        in -= 'a' - 1;
        if (in <= 15) {
            ops += (in % 3 ? in % 3 : 3);
        } else if (in <= 19) {
            ops += (in - 15);
        } else if (in <= 22) {
            ops += (in - 19);
        } else {
            ops += (in - 22);
        }
    }
    cout << ops;
    return 0;
}