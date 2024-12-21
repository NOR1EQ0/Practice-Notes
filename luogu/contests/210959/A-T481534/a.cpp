#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, bool[3]> map(100);
    int n, a, b, c, in;
    cin >> n >> a;
    while (a--) {
        cin >> in;
        auto ite = map.find(in);
        if (ite != map.end()) {
            
        } else {
            auto pair = map.emplace(in);
            pair.second = true;
        }
    }

    return 0;
}