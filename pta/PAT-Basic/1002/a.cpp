#include <iostream>
#include <string>
#include <cstdlib>
#pragma GCC optimize(2)
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
using namespace std;
string pinyin[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main() {
    IOS;
    string str;
    cin >> str;
    int ans = 0;
    for (auto ch : str) {
        ans += (ch - '0');
    }
    str = to_string(ans);
    for (auto ch: str) {
        cout << pinyin[ch-'0'] << ' ';
    }
    cout << '\n';
    return 0;
}