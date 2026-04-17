#include <bits/stdc++.h>

using namespace std;

bool table[256];

int main() {
    string a,b;
    getline(cin, a);
    getline(cin, b);
    for(auto c: b) table[c] = 1;
    for(auto c: a) if (!table[c]) cout << c;
}