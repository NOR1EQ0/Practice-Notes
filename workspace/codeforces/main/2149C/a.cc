#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;

ll arr[(int)2e5];
ll cp[(int)2e5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while ((t--)) {
        /* code */
        int n, k;
        cin >> (n) >> (k);
        if (n==1) {
            cout << "1\n";
            continue;
        }
        int op = 0;
        vector<ll> v;
        while (n--) {
            v.emplace_back([]() {
                int t;
                return (cin >> t, t);
            });
        }
        const auto len = v.size();
        int tail = v.size();
        for (int i = 0; i < len; i++) {
            
        }
        
        cout << op << '\n';
    }
    return 0;
}