#include <bits/stdc++.h>
using namespace std;
inline int toint(reverse_iterator<string::const_iterator> &ch) {
    return *ch-'0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool carry = false;
    string a,b,c;
    a.reserve(20);
    b.reserve(20);
    c.reserve(20);
    cin >> a >> b;
    for (auto i = a.crbegin(), j = b.crbegin(); i != a.crend() || j != b.crend(); ) {
        int num1 = toint(i);
        int num2 = toint(j);
        
    }
    return 0;
}