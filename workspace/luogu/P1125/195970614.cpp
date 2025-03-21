#include <bits/stdc++.h>

using namespace std;
bool isprime(int x) {
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;
    for (int i = 3; i < x; ++i) {
        if (!(x % i)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int maxn=0, minn;
    map<char, int> map;
    string in;
    cin >> in;
    in.reserve(101);
    for (auto i : in) {
        auto search = map.find(i);
        if (search != map.end()) {
            search->second++;
        } else {
            map.emplace(i, 1);
        }
    }
    minn = map.begin()->second;
    for (auto i : map) {
        if (maxn < i.second) maxn = i.second;
        if (minn > i.second) minn = i.second;
    }
    if (isprime(maxn - minn)) {
        cout << "Lucky Word\n" << maxn - minn;
    } else {
        cout << "No Answer\n0";
    }
    putchar('\n');
    return 0;
}