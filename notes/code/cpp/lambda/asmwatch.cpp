#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vec;
    auto is_odd = [](const int x) {
        return x % 2;
    };
    for (int i = 0; i < 15; ++i) {
        int tmp;cin>>tmp;vec.push_back(tmp);
    }
    for (auto &i: vec) {
        if (
            is_odd(i)
        ) 
        cout << i << ' ';
    }
    cout.put('\n');
    return 0;
}