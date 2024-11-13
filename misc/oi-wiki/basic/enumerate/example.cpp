#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr) {
    int ans = 0;
    for (auto i = arr.begin(); i != arr.end(); ++i) {
        for (auto j = i; j < arr.end(); ++j) {
            if (*i + *j == 0) ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int in;
        cin >> in;
        arr.emplace_back(in);
    }
    cout << solve(arr) << endl;
    return 0;
}
