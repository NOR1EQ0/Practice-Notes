#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
    using ll = long long;
    using ull = unsigned long long;

public:
    int minMergedInteger(vector<int>& nums) {
        vector<int> res;
        char buf[16];
        const auto size = nums.size();
        for (size_t i = 0; i < size; i++) {
            auto idx = sprintf(buf, "%d", nums[i]);
            if (i + 1 < size) {
                sprintf(buf + idx, "%d", nums[i + 1]);
                i++;
            }
            auto num = atoi(buf);
            res.push_back(num);
        }
        return *ranges::min_element(res);
    }
};