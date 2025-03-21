#include <bits/stdc++.h>

using namespace std;

vector<string> hanzi = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

inline void print(char val, bool whitespace) {
    if (val == '-') {
        cout << "fu";
    } else {
        cout << hanzi[val-'0'];
    }
    if (whitespace) cout << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in;
    cin >> in;
    for (auto i = in.begin(); i != in.end() - 1; ++i) {
        print(*i, true);
    }
    print(in.back(), false);
    return 0;
}