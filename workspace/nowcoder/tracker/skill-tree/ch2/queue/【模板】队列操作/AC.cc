#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    queue<int> q;
    while (t--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            q.push(x);
        }
        if (op == 2) {
            if (q.empty()) cout << "ERR_CANNOT_POP\n";
            else q.pop();
        }
        if (op == 3) {
            if (q.empty()) cout << "ERR_CANNOT_QUERY\n";
            else cout << q.front() << '\n';
        }
        if (op == 4) {
            cout << q.size() << '\n';
        }
    }
}