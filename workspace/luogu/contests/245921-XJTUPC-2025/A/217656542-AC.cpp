#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cards[3];
    cin >>
        cards[0] >>
        cards[1] >>
        cards[2];
    int score =
        cards[0] +
        cards[1] +
        cards[2];
    if (cards[0] == cards[1] && cards[0] == cards[2]) {
        cout << score + 100;
    } else {
        cout << score;
    }
    cout << '\n';
    return 0;
}