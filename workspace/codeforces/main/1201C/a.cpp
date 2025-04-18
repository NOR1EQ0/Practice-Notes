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
    while (k) {
        auto fret = find_if(vec.begin() + mid, vec.end(), [&vec, &mid](int& i) { return i != vec[mid];});
        if (vec[mid] >= vec.back()) {
            
        }
        if (fret == vec.end()) {
            vec[mid] += (k / (mid + 1));
            break;
        }
        vec[mid]++;
        auto it = upper_bound(fret, vec.end(), vec[mid], greater<int>());
        it = find_end(it, vec.end(), it, it + 1);
        if (it != vec.end()) {
            iter_swap(it, vec.begin() + mid);
        }
        k--;
    }
    cout << vec[mid] << '\n';
    return 0;
}