#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll potatoes{}, total{};
    for (int i = 0; i < n; i++) {
        int sugar, price;
        cin >> sugar >> price;
        if (sugar >= 500 && price < 500) {
            potatoes++;
            total += price;
        }
    }
    cout << potatoes << ' ' << total << '\n';
}