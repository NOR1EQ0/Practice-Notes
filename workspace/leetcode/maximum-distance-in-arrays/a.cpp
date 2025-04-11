#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
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