#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2;
    vector<short> output;
    bool carry = false;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    str1.reserve(36);
    str2.reserve(36);
    output.reserve(36);
    cin >> str1 >> str2;
    for (auto i = str1.rbegin(), j = str2.rbegin(); i != str1.rend() || j != str2.rend(); ) {
        short num = 0;
        if (i != str1.rend()) num += (*(i++) - '0');        
        if (j != str2.rend()) num += (*(j++) - '0');
        if (carry) num += 1;
        if (num >= 10) {
            carry = true;
            output.push_back(num - 10);
        } else {
            carry = false;
            output.push_back(num);
        }
    }
    // print
    if (carry) cout << 1;
    for (auto i = output.rbegin(); i != output.rend(); ++i) {
        cout << *i;
    }
    cout << '\n';
    return 0;
}