#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    // vector<int> departments(m);
    vector<int> diff(m);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a != b) {
            diff[a-1]--;
            diff[b-1]++;
        }
    }
    for(auto i: diff) {
        cout << i << '\n';
    }
}