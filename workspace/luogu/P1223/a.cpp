#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    ull total = 0ull;
    multimap<ull, size_t> twater;
    ull tmp;cin >> tmp;
    twater.emplace(tmp, 0);
    for (int i = 1; i < n; ++i) {
        cin >> tmp;
        twater.emplace(tmp, i + 1);
    }
    vector<ull> vec(n);vec[0]=0;
    auto head = twater.begin().operator*().first;
    auto mapit = twater.begin();
    for (int i = 1; i < n; ++i) {
        vec[i] = mapit.operator*().first + vec[i - 1];
        mapit = next(mapit);
    }
    return 0;
    for (const auto [ignore, index] : twater) {
        cout << index << ' ';
    }
    return 0;
}