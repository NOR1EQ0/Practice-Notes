#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,x;cin>>r>>x;
    if (greater_equal()(r, 1600) && less_equal()(r, 2999) && x == 1) {
        cout << "Yes\n";
    } else if (greater_equal()(r, 1200) && less_equal()(r, 2399) && x == 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}