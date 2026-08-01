#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<ll> presum(n);
    // vector<ll> sufsum(n);
    presum[0] = s[0] == 'o';
    // sufsum[n - 1] = s.back() == 'o';
    for (int i = 1; i < n; i++) {
        presum[i] = ((s[i] == 'o') + presum[i - 1]);
    }
    // for (int i = n - 2; i >= 0; i--) {
    //     sufsum[i] = ((s[i] == 'o') + sufsum[i + 1]);
    // }
    for (int i = 0; i < n; i++) {
        int candy = i + 1;
        int cur_hit = presum[i];
        int find_end = i + cur_hit + 1;
        for (int j = i + 1; j < min(find_end, n); j++) {
            candy++;
            if (s[j] == 'o') {
                find_end++;
            }
        }
        cout << candy << '\n';
    }
}