#include <bits/stdc++.h>

using namespace std;
static constexpr int MAX = 1<<7;
int ability[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    n = 1<<n;
    for (int i = 0; i < n; ++i) cin >> ability[i];
    
    return 0;
}