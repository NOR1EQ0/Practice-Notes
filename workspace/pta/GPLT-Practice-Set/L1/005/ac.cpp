#include <bits/stdc++.h>

using namespace std;
typedef struct{
    uint64_t id;
    short pos;
}seat;

seat seats[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int stus, m;
    cin >> stus;
    while (stus--) {
        uint64_t id;
        int preserve, pos;
        cin >> id >> preserve >> pos;
        preserve--, pos--;
        if (seats[preserve].id != 0) {
            seats[pos].id = id;
            seats[pos].pos = pos+1;
        } else {
            seats[preserve].id = id;
            seats[preserve].pos = pos+1;
        }
    }
    cin >> m;
    while (m--) {
        int in;
        cin >> in;
        in--;
        cout << seats[in].id << ' ' << seats[in].pos << '\n';
    }
    return 0;
}