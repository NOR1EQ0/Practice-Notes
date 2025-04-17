#include <bits/stdc++.h>

using namespace std;

string boy = "boy";
string girl = "girl";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    str.reserve(300);
    cin >> str;
    for (const auto& i : str) {
        if (i == '.') {
            continue;
        }
        if (i == 'b') {
            auto it = str.begin() + (&i - &str[0]);
            auto misit = mismatch(it, str.end(), boy.begin()+1).first;
            
        }
    }
    return 0;
}