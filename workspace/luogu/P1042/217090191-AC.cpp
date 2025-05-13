#include <bits/stdc++.h>

using namespace std;

int f[2] = { 11, 21 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string buffer;
    buffer.reserve(26);
    string record;
    record.reserve((25 + 1) * 2502);
    while (true) {
        cin >> buffer;
        auto e = buffer.find('E');
        if (e != buffer.npos) {
            record += buffer.substr(0, e);
            /**
             * 之前脑抽了写成substr(e-1)，不知怎得把substr的第一个参数记成子串的最后一个字符了，竟然把substr想成倒着找来截取字串的我也是离谱...
             */
            break;
        }
        record += buffer;
    }
    for (auto num : f) {
        int me = 0, enemy = 0;
        for (const auto i : record) {
            if (i == 'W') me++; else enemy++;
            if (max(me, enemy) >= num and abs(me - enemy) >= 2) {
                cout << me << ':' << enemy << '\n';
                me = enemy = 0;
            }
        }
        cout << me << ':' << enemy << "\n\n";
    }

    return 0;
}