#include <bits/stdc++.h>

using namespace std;

uint16_t arr[10];
char in[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>in;
    for (char* i = in; *i; ++i) {
        arr[*i-'0']++;
    }
    for (int i = 0; i < 10; ++i) {
        if (arr[i] != 0)
        {cout << i << ":" << arr[i] << '\n';}
    }
    return 0;
}