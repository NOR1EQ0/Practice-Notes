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
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        long ascore{}, bscore{};
        for (int i = 0; i < n; i++) {
            
        }
    } while (next_permutation(p.begin(), p.end()));

    printf("%u %u %u\n", win, lose, draw);
}