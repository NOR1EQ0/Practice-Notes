#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    vector<int> anum;
    vector<int> bnum;

    vector<int> outnum;

    for (auto i = a.rbegin(); i != a.rend(); i++) {
        anum.push_back(*i - '0');
    }
    for (auto i = b.rbegin(); i != b.rend(); i++) {
        bnum.push_back(*i - '0');
    }

    int minlen = min(a.size(), b.size());
    auto& biggernum = a.size() < b.size() ? bnum : anum;
    bool carry = 0;
    for (int i = 0; i < minlen; i++) {
        auto sum = anum[i] + bnum[i] + carry;
        carry = sum >= 10;
        outnum.push_back(sum - 10 * carry);
    }
    for (int i = minlen; i < biggernum.size(); i++) {
        auto sum = biggernum[i] + carry;
        carry = sum >= 10;
        outnum.push_back(sum - 10 * carry);
    }
    if (carry) outnum.push_back(1);
    long long cnt{};
    for (auto i: outnum) {
        cnt += i;
    }
    cout << cnt << '\n';
}
