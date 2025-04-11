#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ull = unsigned long long;
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ull ans = 0;
        vector<pair<int, int>> vec1;
        for (auto i : arrays) {
            bool exist = (find(vec1.begin(), vec1.end(), pair<int, int>(*i.begin(), *i.rbegin())) != vec1.end());
            vec1.emplace_back(*i.begin(), *i.rbegin());
        }
        auto vlen = vec1.size();
        for (int i = 0; i < vlen; ++i) {
            for (int j = i + 1; j < vlen; ++j) {
                array<unsigned, 4> calc;
                calc[0] = abs(vec1[i].first - vec1[j].first);
                calc[1] = abs(vec1[i].first - vec1[j].second);
                calc[2] = abs(vec1[i].second - vec1[j].first);
                calc[3] = abs(vec1[i].second - vec1[j].second);
                auto nums = *max_element(calc.begin(), calc.end());
                ans = max((ull)(nums), ans);
            }
        }
        return static_cast<int>(ans);
    }
};

int main() {
    Solution sol;
    vector<pair<vector<vector<int>>, int>> inputVec = {
        {
            { {1,2,3}, {4,5}, {1,2,3} }, 4
        },{
            { {1}, {1} }, 0
        }
    };
    for (int i = 0; i < inputVec.size(); ++i) {
        cout << "Testcase " << i + 1 << " - Expected: " << inputVec[i].second << " | Calculation: " << sol.maxDistance(inputVec[i].first) << '\n';
    }
    return 0;
}