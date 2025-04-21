#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;cin >> n >> m;
    vector<int> vec(m);
    for (int i = 0;i < m;++i)cin >> vec[i];
    // selection sort (Best/Average/Worst time: O(n^2))
    for (int i = 0;i < m;++i) {
        int ith = i;
        for (int j = i + 1; j < m; ++j) {
            if (vec[j] < vec[ith]) { ith = j; }
        }
        swap(vec[ith], vec[i]);
    }
    for (int i = 0;i < m - 1;++i)
        cout << vec[i] << ' ';
    cout << vec[m - 1];
    return 0;
}