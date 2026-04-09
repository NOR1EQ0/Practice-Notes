#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    queue<size_t> q;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            size_t x;
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