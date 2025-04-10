#include <bits/stdc++.h>

using namespace std;
char forrest[12][12];
int time = 0;

typedef struct {
    int x;
    int y;
}position;
position posbuf, cow, farmer;

void move(int x, int y, int direction) {

}

void findItem(int x, int y, int direction, char item) {
    if (direction == 0) {
        for (int i = y - 1; i >= 0; --i) {
            if (forrest[i][x] == item) { posbuf.x = x; posbuf.y = i; return; }
        }
    } else if (direction == 1) {
        for (int i = x + 1; i < 12; ++i) {
            if (forrest[y][i] == item) { posbuf.x = i; posbuf.y = y; return; }
        }
    } else if (direction == 2) {
        for (int i = y + 1; i < 12; ++i) {
            if (forrest[i][x] == item) { posbuf.x = x; posbuf.y = i; return; }
        }
    } else {
        for (int i = x - 1; i >= 0; --i) {
            if (forrest[y][i] == item) { posbuf.x = i; posbuf.y = i; return; }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // start direction: North
    /**     0 N
     *      |
     * W 3--+--1 E
     *      |
     *      2 S
     */

     // set boundary
    memset(forrest[0], '*', sizeof(char) * 12);
    memset(forrest[11], '*', sizeof(char) * 12);
    for (int i = 0; i < 12; ++i) {
        forrest[i][0] = '*';
    }

    // read
    for (int i = 0; i < 10; ++i) {
        cin >> (forrest[i + 1] + 1);
        if ()
        forrest[i + 1][11] = '*'; // set right boundary
    }

    // solve


    return 0;
}