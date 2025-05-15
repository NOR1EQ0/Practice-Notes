#include <bits/stdc++.h>

using namespace std;
const int MAX = 4e3 + 5;
uint8_t result[MAX][MAX];

inline void times(string& a, string& b) {
    auto [alen, blen] = pair<size_t, size_t>(a.length(), b.length());
    string* str[2] = { &a, &b };
    int startstr = 0;
    if (alen > blen) {
        startstr = 1;
    }
    vector<size_t> tmp;
    auto maxlen = max(alen, blen);
    auto minlen = min(alen, blen);
    auto it_a = a.rbegin(), it_b = b.rbegin();
    size_t carry = 0;
    auto upper_rb = str[1 - startstr]->crbegin();
    auto lower_rb = str[startstr]->crbegin();
    for (int i = 0; i < minlen; ++i) {
        auto upper_it = str[1 - startstr]->crbegin();
        auto lower_it = str[startstr]->crbegin() + i;
        for (int j = 0; j <= maxlen; ++j) {
            auto num = (*upper_it ? *upper_it - '0' : 0) * (*lower_it ? *lower_it - '0' : 0) + carry;
            // cout << num << ' ' << flush;
            carry = num / 10;
            // cout << carry << ' ' << flush;
            num %= 10;
            // cout << num << endl;
            result[i][j + i] = static_cast<uint8_t>(num);
            upper_it++;
        }
    }
    vector<int> vec(4050);
    for (int i = 0; i < maxlen + minlen; ++i) {
        int tmp = 0;
        for (int j = 0; j < minlen; ++j) {
            tmp += result[j][i];
        }
        tmp += carry;
        carry = tmp / 10;
        vec[i] = (tmp % 10);
    }
    auto complete = maxlen + minlen;
    while (carry) {
        int tmp = carry % 10;
        carry %= 10;
        vec[complete] = tmp;
        complete++;
    }
    complete--;
    for (; vec[complete] == 0; complete--);
    for (int i = complete; i >= 0; --i) {
        cout << vec[i];
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    a.reserve(2020);
    b.reserve(2020);
    cin >> a >> b;
    if (a == "0" || b == "0") { cout << "0\n"; return 0; }
    times(a, b);
    return 0;
}