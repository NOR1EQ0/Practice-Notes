#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ull> vec;
    vec.reserve((int)2e5);
    ull n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        ull num;
        cin >> num;
        vec.emplace_back(num);
    }
    ull a = *max_element(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) {
        
    }
    return 0;
}