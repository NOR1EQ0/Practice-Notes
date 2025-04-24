#include <bits/stdc++.h>

using namespace std;
string str;

int main(int argc, char const* argv[]) {
    str.reserve(20);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while (t--) {
        int n;cin >> n;
        cin >> str;
        int popcnt = count(str.begin(), str.end(), '1');
        int ones = 0;
        for (const auto& i: str) {
            if (i == '1') {
                ones += (popcnt - 1);
            } else {
                ones += (popcnt + 1);
            }
        }
        cout << ones << '\n';
    }
    return 0;
}
