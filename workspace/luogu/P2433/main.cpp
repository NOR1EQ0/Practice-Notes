#include <iomanip>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    switch (t) {
        case 1:
            cout << "I love Luogu!\n";
            break;
        case 2:
            cout << "6 4\n";
            break;
        case 3:
            cout << "3 12 2\n";
            break;
        case 4: {
            cout << setprecision(6) << 500.0 / 3 << '\n';
        } break;
        case 5:
            
            break;
        case 6:
            break;
        case 7:
            cout << "0\n";
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
    }
    return 0;
}