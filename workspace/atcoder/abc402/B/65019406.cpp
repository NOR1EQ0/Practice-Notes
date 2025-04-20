#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);int q; cin >> q;
    queue<int> q1;
    while (q--) {
        int op; cin >> op;
        if (op-1) {
            cout << q1.front() << '\n'; q1.pop();
        } else {
            int tmp; cin >> tmp; q1.push(tmp);
        }
    }
    return 0;
}