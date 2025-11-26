#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    cout << (s.size() > 1 ? s[s.size() - 2] : '0') << '\n';
}