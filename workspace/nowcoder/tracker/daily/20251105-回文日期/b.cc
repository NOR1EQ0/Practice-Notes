#include <bits/stdc++.h>

using namespace std;

bool is_leap_year(int y) {
    return (!(y % 4) && y % 100) || !(y % 400);
}

struct date {
    int year, mon, day;
};

struct datestr {
    string y, m, d;
};

datestr makedatestr(string& s) {
    return {
        s.substr(0, 4),
        s.substr(4, 2),
        s.substr(6, 2)};
}

date makedate(string& s) {
    return {
        stoi(s.substr(0, 4)),
        stoi(s.substr(4, 2)),
        stoi(s.substr(6, 2))};
}

pair<datestr, date> makedt(string& s) {
    return {makedatestr(s), makedate(s)};
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    auto [ds1, d1] = makedt(a);
    auto [ds2, d2] = makedt(b);
}