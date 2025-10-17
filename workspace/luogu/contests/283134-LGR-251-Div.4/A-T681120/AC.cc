#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios::sync_with_stdio(0), cin.tie(0);
    using ul = uint64_t;
    ul a, b;
    cin.operator>>(a).operator>>(b);
    a---b--;
    cout<<a*b-1<<'\n';
}