#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, b;
    cin >> n >> m >> b;
    vector<int> price;
    price.reserve((int)10e4);
    for (int i = 0; i < n; ++i) {
        int in;
        cin >> in;
        price.emplace_back(in);
    }
}