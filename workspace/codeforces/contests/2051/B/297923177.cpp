#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, arr[3], distance = 0, day = 0, sum = 0;
        cin >> n;
        for (int i = 0; i < 3; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        day += (n / sum) * 3;
        distance += (n / sum) * sum;
        for (int i = 0; i < 3; ++i) {
            if (distance >= n) {
                break;
            }
            distance += arr[i];
            day++;
        }
        cout << day << '\n';
    }

    return 0;
}