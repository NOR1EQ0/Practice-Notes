#include <bits/stdc++.h>

using namespace std;

struct score {
    int w, l;
};

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
            if (e != 0)
                record += buffer.substr(e - 1);
            break;
        }
        record += buffer;
    }
    if (record.empty()) {
        cout << "0:0\n\n0:0\n";
        return 0;
    }
    buffer.erase();
    // 11 score
    #define op(v)  \
    for (auto i = record.begin(); distance(i, record.end()) > 0; ++i) { \
        int me = 0, enemy = 0; \
        while (i != record.end() && me < v && enemy < v) { \
            if (*i == 'W') me++; else enemy++; \
        } \
        cout << me << ':' << enemy << '\n'; \
    }
    op(11);
    cout.put('\n');
    op(21);
    return 0;
}