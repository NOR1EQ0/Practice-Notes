#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> dq(n);
        for (int i = 0; i < n; i++) {
            cin >> dq[i];
        }
        sort(dq.begin(), dq.end(), greater());
        while (!dq.empty()) {
            min_element(dq.begin(), dq.begin() + 3); // Need to avoid out of bound, and actually this code of the line is wrong. But, change it tomorrow, maybe :P
        }
    }
}