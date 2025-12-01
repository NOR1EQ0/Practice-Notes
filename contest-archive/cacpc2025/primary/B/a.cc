#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> dq;
        int tmin;
        cin >> tmin;
        int tmax = tmin;
        dq.push_back(tmin);
        for (int i = 1; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp <= tmin) {
                dq.push_back(tmp);
                tmin = tmp;
            } else {
                if (tmp >= tmax) {
                    dq.push_front(tmp);
                    tmax = tmp;
                } else {
                    dq.push_back(tmp);
                }
            }
        }
        for (auto i : dq) {
            cout << i;
        }
        cout.put('\n');
        // cout << endl;
    }
}