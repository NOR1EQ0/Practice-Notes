#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else if (op == 2) {
            cout << pq.top() << '\n';
        } else {
            pq.pop();
        }
    }
}