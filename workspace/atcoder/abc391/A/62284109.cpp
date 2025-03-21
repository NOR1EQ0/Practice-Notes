#include <bits/stdc++.h>

using namespace std;

int main() {
    char in;
    while ((in=getchar())!=EOF)
    {
        switch (in)
        {
        case 'N':
            cout << 'S';
            break;
        case 'E':
            cout << 'W';
            break;
        case 'W':
            cout << 'E';
            break;
        case 'S':
            cout << 'N';
            break;
        default:
            break;
        }
    }
    cout << '\n';
    return 0;
}