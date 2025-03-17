#include <bits/stdc++.h>
#define a1 1
using namespace std;

// inline int mypow(int, int&);
inline int mypow(int val, int& layer) {
    int last = 0;
    for (int i = 0, now = 0; now <= val;++i) {
        now = (i * i) * 2 - 1;
        if (now <= val) {
            layer = i;
            last = now;
        }
    }
    return last;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n;
    char sign;
    cin >> n >> sign;
    int layer = 0;
    // Sn = (n*n)*2-1
    auto tower = mypow(n, layer);
    auto rest = n - tower;
    for (int i = 1; i <= layer; ++i) {
        int signcnt = (layer - i) * 2 + 1;
        for (int j = 0; j < i - 1; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < signcnt; ++j) {
            cout << sign;
        }
        cout << '\n';
    }
    for (int i = 1; i < layer; ++i) {
        int signcnt = i * 2 + 1;
        int whitespace = layer - i - 1;
        for (int j = 0; j < whitespace; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < signcnt; ++j) {
            cout << sign;
        }
        cout << '\n';
    }
    cout << rest << '\n';
    return 0;
}