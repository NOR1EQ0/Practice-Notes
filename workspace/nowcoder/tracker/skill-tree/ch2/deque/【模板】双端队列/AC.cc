#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    deque<int> dq;
    int n;
    cin >> n;
    while (n--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            dq.push_front(x);
        }
        if (op == 2) {
            cin >> x;
            dq.push_back(x);
        }
        if (op == 3) {
            cout << dq.front() << '\n';
            dq.pop_front();
        }
        if (op == 4) {
            cout << dq.back() << '\n';
            dq.pop_back();
        }
    }
}