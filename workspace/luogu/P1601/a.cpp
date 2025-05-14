#include <bits/stdc++.h>

using namespace std;

constexpr const auto wndsize = numeric_limits<uint64_t>::digits10;
constexpr const uint64_t max10 = static_cast<uint64_t>(1e19);

inline uint64_t pow10(size_t exponent) {
    uint64_t tmp = 1;
    for (int i = 1; i <= exponent; ++i) {
        tmp *= 10;
    }
    return tmp;
}

void str2bigint(const string& str, vector<uint64_t>& bigint) {
    uint64_t tmp = 0;
    for (auto i = str.rbegin(); i < str.rend(); ) {
        for (int j = 0; j < wndsize && i < str.rend(); ++j) {
            auto num = *i - '0';
            tmp = tmp + num * pow10(j);
            ++i;
        }
        bigint.insert(bigint.begin(), tmp);
        tmp = 0;
    }
}

vector<uint64_t> bigintplus(vector<uint64_t>& a, vector<uint64_t>& b) {
    vector<uint64_t> ret;
    ret.reserve(max(a.size(), b.size()) + 1);
    int nextvec = 0;
    if (a.size() < b.size()) {
        nextvec = 1;
    }
    vector<uint64_t>* v[2] = { &a,&b };
    bool carry = false;
    auto ait = a.rbegin(), bit = b.rbegin();
    decltype(ait) itarr[2] = { ait, bit };
    while (itarr[0] != a.rend() && itarr[1] != b.rend()) {
        auto tmp = *ait + *itarr[1] + carry;
        if (tmp >= max10 || tmp < *itarr[0]) {
            tmp -= max10;
            carry = true;
        } else {
            carry = false;
        }
        ret.emplace_back(tmp);
        itarr[0]++, itarr[1]++;
    }
    auto& nxtit = itarr[nextvec];
    for (; nxtit != v[nextvec]->rend(); nxtit++) {
        auto tmp = *nxtit + carry;
        if (tmp >= max10 || tmp < *itarr[0]) {
            tmp -= max10;
            carry = true;
        } else {
            carry = false;
        }
        ret.emplace_back(tmp);
        nxtit++;
    }
    if (carry) {
        ret.back()++;
        if (ret.back() >= max10) {
            ret.back() -= max10;
            ret.emplace_back(1);
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<uint64_t> av, bv;
    string a, b;
    cin >> a >> b;
    str2bigint(a, av);
    str2bigint(b, bv);
    auto vec = bigintplus(av, bv);
    for (const auto i: vec) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}