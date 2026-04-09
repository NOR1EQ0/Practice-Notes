#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string op;
    while (t--) {
        stack<size_t> s;
        int n;
        cin >> n;
        while (n--) {
            cin >> op;
            if (op == "push") {
                size_t x;
                cin >> x;
                s.push(x);
            }
            if (op == "pop") {
                if (s.empty()) cout << "Empty\n";
                else
                    s.pop();
            }
            if (op == "query") {
                if (s.empty()) cout << "Anguei!\n";
                else
                    cout << s.top() << '\n';
            }
            if (op == "size") {
                cout << s.size() << '\n';
            }
        }
    }
}