#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long sum{};
        cin >> n;
        int last, current, first;
        cin >> last;
        first = last;
        if (last == -1) {
            cout << "0\n0 ";
            for (int i = 1; i < n - 1; i++) {
                cin >> current;
                cout << (current == -1 ? 0 : current) << ' ';
            }
            cin >> current;
            if (current == -1) {
                cout << 
            }
        } else {
            ostringstream oss;
            for (int i = 1; i < n; i++) {
                cin >> current;
                sum += (current - last);
                oss << (current == -1 ? 0 : current) << ' ';
                last = current;
            }
            if (current == -1) {
                cout << "0\n"
                     << first << ' ';
            } else {
                cout << abs(sum) << '\n'
                     << first << ' ';
            }
            cout << oss.str();
        }
        cout << '\n';
    }
}