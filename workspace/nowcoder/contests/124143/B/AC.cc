#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        long balance = 0;
        vector<long> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        long last = v[0] - x;
        if (last < 0) {
            cout << "No\n";
            continue;
        }
        long current;

        bool alive = true;

        for (int i = 1; i < n; i++) {
            current = v[i];
            // current -= x;
            // if (current < 0) {
            //     last += current;
            // }
            // if (last < 0) {
            //     alive = false;
            //     break;
            // }
            last -= x;
            if (last < 0) {
                current += last;
            }
            if (current < 0) {
                alive = false;
                break;
            }
            last = current;
        }

        cout << (alive ? "Yes\n" : "No\n");
    }
}