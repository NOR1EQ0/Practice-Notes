#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
bool is_composite[(int)1e9 + 5];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) primes.emplace_back(i);
        for (auto p : primes) {
            if (1ll * p * i > n) break;
            is_composite[1ll * p * i] = true;
            if (i % p == 0) break;
        }
    }
}

class Solution {
public:
    bool completePrime(int num) {
        sieve(num);
        if (binary_search(primes.begin(), primes.end(), num) == false) return false;
        // unordered_set<int> us;
        // us.reserve(primes.size());
        // for (auto i : primes) {
        //     us.emplace(i);
        // }
        string numstr = to_string(num);
        auto numwidth = numstr.size();
        vector<int> words;
        words.reserve(numstr.size() * 2 + 5);

        string prefix, suffix;
        prefix.reserve(numwidth), suffix.reserve(numwidth);
        for (int i = 0; i < numwidth - 1; i++) {
            prefix += (numstr[i]);
            words.emplace_back(stoi(prefix));
        }
        for (int i = numwidth - 1; i > 0; i--) {
            suffix += (numstr[i]);
            words.emplace_back(stoi(suffix));
        }

        for (auto i : words) {
            if (binary_search(primes.begin(), primes.end(), i)) return false;
        }
        return true;
    }
};

int main() {
    vector<pair<int, bool>> v = {
        {23, true}, {39, false}, {7, true}, 
        {1379657, false},
        {27, false}
    };
    cout << boolalpha;
    for (auto& i : v) {
        auto res = Solution().completePrime(i.first);
        cout << "Number: " << i.first << " | Expected: " << i.second << " | Output " << res << endl;
        primes.clear();
        fill(is_composite, is_composite + ((int)1e9 + 5), false);
    }
}