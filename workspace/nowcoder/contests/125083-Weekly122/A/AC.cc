#include <bits/stdc++.h>

using namespace std;
char str[] = "A B C D E F G H I J K L M";

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    str[n * 2] = '\0';
    cout << str << '\n';
}