#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned n;
    cin >> n;
    int c = __builtin_clz(n);
    cout<<((1u << 31u) >> c);
}