#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node./
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> ret;
    vector<int> path;

    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode* current = root;
        char meetRoot = 0;
        recurTail(*current);
        return move(ret);
    }

    void recurTail(TreeNode& node) {
        if (isLeaf(node)) {
            string item;
            #define RIGHT "->"
            for (auto i = path.begin(); i != path.end(); ++i) {
                item += (to_string(*i) + RIGHT);
            }
            item += to_string(node.val);
            ret.emplace_back(item);
            
        } else {
            path.emplace_back(node.val);
            if (node.left) {
                recurTail(*node.left);
            }
            if (node.right) {
                recurTail(*node.right);
            }
            if (!path.empty()) path.pop_back();
        }
    }

    inline bool isLeaf(TreeNode& node) {
        return !(node.left || node.right);
    }
};

int main() {
    // testcase 1
    Solution loc;
    TreeNode nodes[4];
    TreeNode single(1);
    nodes[0].val = 1;
    nodes[1].val = 2;
    nodes[2].val = 3;
    nodes[3].val = 5;
    nodes[0].left = &(nodes[1]);
    nodes[0].right = &(nodes[2]);
    nodes[1].right = &(nodes[3]);
    auto ret = loc.binaryTreePaths(&(nodes[0]));
    for (auto i: ret) {
        cout << i << '\n';
    }
    auto singleRet = loc.binaryTreePaths(&single);
    cout << single.val << '\n';

    TreeNode nodes2[3];
    nodes2[0].val = 1;
    nodes2[1].val = 2;
    nodes2[2].val = 3;
    nodes2[0].left = &(nodes2[1]);
    nodes2[0].right = &(nodes2[2]);
    auto ret2 = loc.binaryTreePaths(&(nodes2[0]));
    for (auto i: ret2) {
        cout << i << '\n';
    }
    return 0;
}  