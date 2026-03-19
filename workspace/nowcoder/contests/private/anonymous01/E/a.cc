#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string b;
        cin >> n >> b;
        string dict = b;
        sort(dict.begin(), dict.end());
        dict.erase(unique(dict.begin(), dict.end()), dict.end());
        cout << dict << '\n';
    }
}