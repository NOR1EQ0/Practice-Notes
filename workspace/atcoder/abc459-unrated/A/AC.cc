#include <bits/stdc++.h>

using namespace std;

char str[] = "HelloWorld";

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x;
    cin >> x;
    *(str + x - 1) = 0;
    cout << str << str + x;
}