#include <bits/stdc++.h>

using namespace std;

char seq[] = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int direction = 0;
    for (auto c: seq) {
        if (!isdigit(c)) break;
        int op = c - '0';
        if (op == 0) {
            if (direction == 0) direction = 3;
            else if (direction == 1) direction = 2;
            else if (direction == 2) direction = 1;
            else direction = 0;
        }
        if (op == 1) {
            if (direction == 1) direction = 3;
            else if (direction == 3) direction = 1;
        }
        if (op == 2) {
            if (direction == 0) direction = 1;
            else if (direction == 1) direction = 0;
            else if (direction == 2) direction = 3;
            else direction = 2;
        }
        if (op == 3) {
            if (direction == 0) direction = 2;
            else if (direction == 2) direction = 0;
        }
        if (op == 4) {
            direction = (direction + 1) % 4;
        }
        if (op == 5) {
            if (!direction) direction = 3;
            else direction--;
        }
        cout << direction;
    }
}