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
        vec.emplace_back(-tmp);
    }
    sort(vec.begin(), vec.end());
    while (k--) {
        vec[mid]--;
        auto it = upper_bound(vec.rbegin() + mid + 1, vec.rend(), vec[mid]);
        if (it != vec.rend()) {
            iter_swap(it, vec.rbegin() + mid);
        }
    }
    cout << -vec[mid] << '\n';
    return 0;
}