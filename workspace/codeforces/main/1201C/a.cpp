#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int mid = n / 2;
    vector<int> vec;
    while (n--) {
        int tmp;
        cin >> tmp;
        vec.emplace_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for (int i = mid; i < )
    cout << vec[mid] << '\n';
    return 0;
}