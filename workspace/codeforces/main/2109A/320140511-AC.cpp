#include <bits/stdc++.h>

using namespace std;

bool arr[105];
bool verdict[104];
int n;

bool dfs(int i) {
    if (i == n - 1) {
        return (arr[i] == verdict[i - 1]);
    }
    if (arr[i] == false) {
        if (verdict[i - 1] == false) {
            verdict[i] = true;
            return dfs(i + 1);
        } else {
            return false;
        }
    } else {
        if (verdict[i - 1] == true) {
            verdict[i] = false;
            if (dfs(i + 1)) {
                return true;
            }
            verdict[i] = true;
            return dfs(i + 1);
        } else {
            verdict[i] = false;
            return dfs(i + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        // prove
        verdict[0] = !arr[0];
        if (!dfs(1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}