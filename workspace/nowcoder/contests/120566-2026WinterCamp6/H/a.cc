#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int x = 0;
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    auto bmaxp = max_element(b.begin(), b.end()) - b.begin();
    for (int i = 0; i < n; i++) {
        int af = max(0, x - a[i]);
        int bf = x ^ b[i];
        if (!af) x = bf;
        else {
            if (i == bmaxp) {
                x = max(af, bf);
            } else {
                x = af;
            }
        }
    }
    cout << x << '\n';
}