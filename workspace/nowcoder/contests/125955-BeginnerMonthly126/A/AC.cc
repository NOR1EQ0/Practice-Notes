#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        auto asub = a.substr(0, a.find('+'));
        auto bsub = b.substr(0, b.find('+'));
        auto aplus = a.back() == '+', bplus = b.back() == '+';
        int anum = stoi(asub), bnum = stoi(bsub);
        if (anum > bnum) {
            cout << "Yes\n";
            continue;
        } else if (anum < bnum) {
            cout << "No\n";
            continue;
        } else {
            cout << (aplus ? "Yes\n" : "No\n");
        }
    }
}