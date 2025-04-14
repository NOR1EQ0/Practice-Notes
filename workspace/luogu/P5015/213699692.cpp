#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int in;
    int digits = 0;
    while ((in = cin.get()) != EOF) {
        if (in == ' ' || in == '\n') continue; digits++;
    }
    cout << digits << '\n';
    return 0;
}