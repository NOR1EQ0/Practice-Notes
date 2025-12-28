#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

// #define FILEIN

int main() {
#ifdef FILEIN
    freopen("input.txt", "rb", stdin);
#endif
#ifdef FASTIO
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n - 1);
        ll size = 2;
        // read b array
        for (int i = 0; i < n - 1; i++) cin >> v[i];

        // shift a window
        for (int i = 0; i < n - 1; i++) {
            ll tsize = 1;
            bool fit = 0;
            int fitpos = -1;
            int j = i + 1;
            for (; j < n - 1; j++) {
                if (v[j] == v[j - 1] + 1) {
                    tsize++;
                } else if (v[j] == v[j - 1] + 2 && !fit) {
                    tsize += 2;
                    fitpos = j;
                    fit = true;
                } else {
                    break;
                }
            }
            // tsize += !fit;
            if (fitpos != -1) i = fitpos - 1;
            else{
                i = j - 1;
                tsize++;
            }

            size = max(size, tsize);
        }

        cout << size << '\n';
    }
    return 0;
}