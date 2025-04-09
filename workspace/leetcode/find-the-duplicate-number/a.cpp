#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            //
        }
    };

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> testcases = {
        { {1,3,4,2,2}, 2 },
        { {3,1,3,4,2}, 3 },
        { {3,3,3,3,3}, 3 }
    };
    for (auto i : testcases) {
        cout << "Input: [";
        for (auto j = i.first.begin(); j != i.first.end() - 1; j++) {
            cout << *j << ", ";
        }
        cout << i.first.back() << "] | Expected: " << i.second << " | Calculation: " << sol.findDuplicate(i.first) << '\n';
    }
    return 0;
}