#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;cin >> n >> m;
    vector<int> vec(m);
    for (int i = 0;i < m;++i)cin >> vec[i];
    // selection sort (Best/Average/Worst time: O(n^2))
    sort(vec.begin(), vec.end());
    for (int i = 0;i < m - 1;++i)
        cout << vec[i] << ' ';
    cout << vec[m - 1];
    return 0;
}