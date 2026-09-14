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
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            if (!rowShift[i]) {
                continue;
            }
            rotate(grid[i].begin(), grid[i].begin() + rowShift[i], grid[i].end());
        }
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            auto shiftStep = colShift[i];
            if (!shiftStep) {
                continue;
            }
            auto shiftCol = i;
            for (int j = 0; j < n; j++) {
                arr[j] = grid[(j + shiftStep) % n][i];
            }
            for (int j = 0; j < n; j++) {
                grid[j][i] = arr[j];
            }
        }
        return grid;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> rowShift = {1, 2, 0};
    vector<int> colShift = {2, 2, 1};
    auto ret = Solution().cyclicShift(3, grid, rowShift, colShift);
}