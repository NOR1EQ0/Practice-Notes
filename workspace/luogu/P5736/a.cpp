#include <bits/stdc++.h>

using namespace std;

bool isprime(const int& n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (!(n % 2) || !(n % 3)) return true;
    for (int i = 5; i * i <= n; i += 6) {
        if (!(n % i) || !(n % (i + 2))) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}