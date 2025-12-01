#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

void pop_front_n(deque<ull>& dq, size_t n) {
    for (size_t i = 0; i < n; i++) {
        dq.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, c;
    size_t coins = 0;
    cin >> n >> c;
    deque<ull> dq;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp <= c) {
            dq.emplace_back(tmp);
        } else {
            coins++;
        }
    }

    n = dq.size();
    for (int i = 0; i < n; i++) {
        
    }
}