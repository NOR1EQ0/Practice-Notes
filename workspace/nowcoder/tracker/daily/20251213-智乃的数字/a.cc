#include <bits/stdc++.h>

using namespace std;
constexpr auto MAXN = (int)1e9 + 1;
constexpr auto MOD = (int)1e9 + 7;

int chinos[MAXN];
size_t pindex = 0;

void push_back(int* p, int val) {
    p[pindex] = val;
    pindex++;
}

void init_chinos() {
    char str[16];
    for (int i = 3; i < MAXN; i++) {
        if (i % 5 == 0) {
            push_back(chinos, i);
            continue;
        }
        sprintf(str, "%d", i);
        auto cnt = 0;
        for (char* p = str; *p; p++) {
            cnt += (*p - '0');
        }
        if (cnt % 3 == 0) {
            push_back(chinos, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    init_chinos();
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cout << chinos[k-1] << '\n';
    }
}