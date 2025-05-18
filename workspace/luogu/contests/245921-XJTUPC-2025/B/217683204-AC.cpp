#include <bits/stdc++.h>

using namespace std;

char confuse[] = "1iIl";
int in;


inline bool isNotConfused() {
    for (int i = 0; i < 4; ++i) {
        if (in == confuse[i])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    cin.get();
    cin.get();
    while ((in = cin.get()) != EOF) {
        if (isNotConfused()) {
            cout << static_cast<char>(in);
        }
    }
    return 0;
}