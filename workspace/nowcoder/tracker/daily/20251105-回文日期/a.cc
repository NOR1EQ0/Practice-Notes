#include <bits/stdc++.h>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
    int year;
    int mon;
    int day;
};

void mkdate(date& d, const string& s) {
    d = {
        .year = stoi(s.substr(0, 4)),
        .mon = stoi(s.substr(4, 2)),
        .day = stoi(s.substr(6, 2))};
}

bool is_leap_year(int y) {
    return (!(y % 4) && y % 100) || !(y % 400);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    date d1, d2;
    mkdate(d1, a);
    mkdate(d2, b);
    size_t cnt{};
    for (int i = d1.year; i <= d2.year; i++) {
        bool leap = is_leap_year(i);
        auto ystr = to_string(d1.year);
        reverse(ystr.begin(), ystr.end());
        auto dstr = ystr.substr(0, 2), mstr = ystr.substr(2, 2);
        auto rmon = stoi(mstr);
        auto rday = stoi(dstr);
        auto rmon_daycnt = days[rmon];
        if (leap && rmon == 2) {
            rmon_daycnt++;
        }

        if (rmon > 12 || rmon <= 0 || rday <= 0 || rday > rmon_daycnt) {
            continue;
        } else {
            if (i == d2.year && rmon <= d2.mon && days[rmon] <= d2.day) {
                cnt++;
            } else {
                if (rday <= d2.day) {
                    cnt++;
                } else {
                    continue;
                }
            }
        }
    }
    cout << cnt << '\n';
}
