#include <bits/stdc++.h>

using namespace std;

string add(string& a, string& b) {
    auto [alen, blen] = pair{ a.length(), b.length() };
    auto [maxlen, minlen] = pair{ alen, blen };
    int carry = 0;
    string* vec[2] = { &a, &b };
    string ret;
    for (auto it_a = a.crbegin(), it_b = b.crbegin(); it_a < a.crend() || it_b < b.crend(); it_a++, it_b++) {
        auto num = carry +
            (it_a < a.crend() ? *it_a - '0' : 0) +
            (it_b < a.crend() ? *it_b - '0' : 0);
        carry = num / 10;
        num %= 10;
        ret.push_back(static_cast<char>(num) + '0');
    }
    if (carry) ret.push_back(static_cast<char>(carry) + '0');
    ranges::reverse(ret);
    // assert(ret.front() != '0');
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    a.reserve(501);
    b.reserve(501);
    cin >> a >> b;
    cout << add(a, b) << '\n';
    return 0;
}