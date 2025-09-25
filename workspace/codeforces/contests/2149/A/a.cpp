#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int neg = 0, pos = 0, zero = 0;
        while (n--) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) neg++;
            else if (tmp == 0)
                zero++;
            else
                pos++;
        }
        int sum = zero;
        if (neg % 2) sum += 2;
        cout << sum << '\n';
    }
    return 0;
}