#include <bits/stdc++.h>
#include "../utils/print"
#define NAME_TO_STRING(v) #v

using namespace std;

inline time_t randnum() {
    auto time = chrono::system_clock::now();
    auto timestamp = chrono::system_clock::to_time_t(time);
    return timestamp;
}

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value, TreeNode* lptr = nullptr, TreeNode* rptr = nullptr) : val(value), left(lptr), right(rptr) {};
    TreeNode() : val(randnum()), left(nullptr), right(nullptr) {};
} *pTreeNode;

inline void assignLeavesOfTreeNode(pTreeNode rootNode, const pTreeNode leftNode, const pTreeNode rightNode) {
    rootNode->left = leftNode;
    rootNode->right = rightNode;
}

void assignLeavesOfTreeNode(TreeNode& rootNode, const pTreeNode leftNode, const pTreeNode rightNode) {
    assignLeavesOfTreeNode(&rootNode, leftNode, rightNode);
}

void assignLeavesOfTreeNode(TreeNode& rootNode, const TreeNode& leftNode, const TreeNode& rightNode) {
    assignLeavesOfTreeNode(&rootNode, const_cast<pTreeNode>(&leftNode), const_cast<pTreeNode>(&rightNode));
}

// preOrder
void _treeTraversalPreOrder(vector<int>& vec, TreeNode& node) {
    if (!&node) return;
    auto isLeave = (node.left == nullptr && node.right == nullptr);
    if (isLeave) {
        vec.emplace_back(node.val);
    } else {
        _treeTraversalPreOrder(vec, *node.left);
        _treeTraversalPreOrder(vec, *node.right);
    }
}

void _treeTraversalInOrder(vector<int>& vec, TreeNode& node) {}

void(*PreOrder)(vector<int>&, TreeNode&) = _treeTraversalPreOrder;

vector<int> treeTraversal(TreeNode& rootNode, void(order)(vector<int>& vec, TreeNode& node)) {
    vector<int> vec;
    order(vec, rootNode);
    return move(vec);
}

int main() {
    cout << "sizeof(" << NAME_TO_STRING(TreeNode) "): " << sizeof(TreeNode) << endl;
    TreeNode root(17);
    pTreeNode n1 = new TreeNode(98);
    pTreeNode n2 = new TreeNode(127);
    assignLeavesOfTreeNode(root, n1, n2);
    auto ret = treeTraversal(root, _treeTraversalPreOrder);
    print_stl_container_element_with_newline(ret);
    return 0;
}