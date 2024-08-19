#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int time = (c * 60 + d) - (a * 60 + b);
    cout << time / 60 << " " << time % 60 << endl;
    return 0;
}