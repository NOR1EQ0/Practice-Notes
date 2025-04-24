#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> p;
    p.reserve((size_t)2e5);
    int t;cin>>t;while (t--) {
        int n,x;cin>>n>>x;
        if (n<=1) {cout << "0\n";continue;}
        for (int i = x - 1; i >= 0; i--) cout << i << ' ';
        for (int i = n - 1; i >= x; i--) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
