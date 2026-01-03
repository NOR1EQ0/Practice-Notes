#include <bits/stdc++.h>

using namespace std;

int zero[2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 2>> v(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        auto& arr = v[b];
        if (arr[0] || arr[1]) {
            bool lexist = arr[0];
        } else {
            if (a > b) {
                arr[1] = a;
            } else {
                arr[0] = a;
            }
        }
    }

    vector<int> stack;
    int layers = 0;
    // preorder
    for (int i = 1; i <= n; i++) {
    }
}