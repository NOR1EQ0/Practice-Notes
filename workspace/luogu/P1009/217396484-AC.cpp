#include <bits/stdc++.h>

using namespace std;

char result[4000][4000];

string add(string& a, string& b) {
    auto [alen, blen] = pair{ a.length(), b.length() };
    auto [maxlen, minlen] = pair{ alen, blen };
    int carry = 0;
    string* vec[2] = { &a, &b };
    string ret;
    for (auto it_a = a.crbegin(), it_b = b.crbegin(); it_a < a.crend() || it_b < b.crend(); it_a++, it_b++) {
        auto num = carry +
            (it_a < a.crend() ? *it_a - '0' : 0) +
            (it_b < b.crend() ? *it_b - '0' : 0);
        carry = num / 10;
        num %= 10;
        ret.push_back(static_cast<char>(num) + '0');
    }
    if (carry) ret.push_back(static_cast<char>(carry) + '0');
    ranges::reverse(ret);
    // assert(ret.front() != '0');
    return ret;
}

inline string times(string& a, string& b) {
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
            carry = num / 10;
            num %= 10;
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
    string ret;
    for (; vec[complete] == 0; complete--);
    for (int i = complete; i >= 0; --i) {
        ret.push_back(static_cast<string::value_type>(vec[i]) + '0');
    } 
    return ret;
}

void solve(int n) {
    string res;
    res.reserve(4000);
    res = "1";
    string sum = "0";
    for (int i = 1; i <= n; ++i) {
        string now = to_string(i);
        res = times(res, now);
        sum = add(sum, res);
    }
    for (const auto i: sum) {
        cout << i;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    solve(n);
    return 0;
}