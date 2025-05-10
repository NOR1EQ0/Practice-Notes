#include <bits/stdc++.h>

using namespace std;

int arr[101];
int tmp[101];

bool check_zero(int m) {
    for (int i = 1; i <= m; ++i) {
        if (tmp[i] == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vec;
    vec.reserve(105);
    int n, m;cin >> n >> m;
    int op = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        tmp[arr[i]]++;
    }
    if (check_zero(m)) {
        cout << "0\n";
        return 0;
    }
    int* last = arr + n - 1;
    while (1) {
        tmp[*last]--;
        last--;
        auto ret = check_zero(m);
        op++;
        if (ret) break;
    }
    cout << op << '\n';
    return 0;
}