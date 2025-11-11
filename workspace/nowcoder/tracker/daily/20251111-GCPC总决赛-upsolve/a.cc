#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    size_t win{}, lose{}, draw{};
    bool aflg = true;
    do {
        do {
            long asco{}, bsco{};
            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    asco++;
                } else if (a[i] < b[i]) {
                    bsco++;
                }
            }
            if (asco > bsco)
                win++;
            else if (asco == bsco)
                draw++;
            else 
                lose++;
        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));
    printf("%u %u %u\n", win, lose, draw);
}