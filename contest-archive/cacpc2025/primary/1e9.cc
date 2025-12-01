#include <bits/stdc++.h>

using namespace std;

int main() {
    set<long> gcdn;
    for (int i = 0; i < (int)1e8 + 9; i++) {
        gcdn.emplace(gcd((long)i, (long)1e8 + 7));
    }
    for (auto i : gcdn) {
        cout << i << ' ';
    }
    cout << endl;
}