#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int bottom = 0;
        int op = 0;
        int len = nums.size();
        unordered_map<int, int> umap;
        for (auto& i : nums) {
            umap[i] += 1;
        }
        while (bottom < len) {
            bool skip = false;
            for (int i = bottom; i < len && i < bottom + 3; ++i) {
                if (umap[nums[i]] > 1) {
                    skip = true;
                    break;
                }
            }
            bool unique = isUnique(umap);
            if (skip) {
                for (int i = bottom; i < len && i < bottom + 3; ++i) {
                    umap[nums[i]] -= 1;
                    if (umap[nums[i]] <= 0) {
                        umap.erase(nums[i]);
                    }
                }
            }
            op += 1;
            bottom += 3;
        }
        return op;
    }

    inline bool isUnique(unordered_map<int, int>& umap) {
        for (auto i : umap) {
            if (i.second > 1)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> inputVec = {
        { {1,2,3,4,2,3,3,5,7}, 2 },
        { {4,5,6,4,4}, 2 },
        { {6,7,8,9}, 0 }
    };
    // Test
    for (auto i : inputVec) {
        cout << "Input: [";
        for (auto j = i.first.begin(); j != i.first.end() - 1; j++) {
            cout << *j << ", ";
        }
        cout << i.first.back() << "] | Expected: " << i.second << " | Calculation: " << sol.minimumOperations(i.first) << '\n';
    }
    return 0;
}