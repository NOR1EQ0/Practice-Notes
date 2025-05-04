#include <bits/stdc++.h>
#include "../utils/print"
#define NAME_TO_STRING(v) #v

using namespace std;

inline int randnum() {
    auto time = chrono::system_clock::now();
    auto timestamp = chrono::system_clock::to_time_t(time);
    srand(timestamp);
    return rand();
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

using BinaryTreeTraversalOrderFunctionType = void(*)(vector<int>&, const TreeNode& node);

// preOrder
void _binaryTreeTraversalPreOrder(vector<int>& vec, const TreeNode& node) {
    vec.emplace_back(node.val);
    if (node.left) _binaryTreeTraversalPreOrder(vec, *node.left);
    if (node.right) _binaryTreeTraversalPreOrder(vec, *node.right);
}

BinaryTreeTraversalOrderFunctionType PreOrder = _binaryTreeTraversalPreOrder;

void _binaryTreeTraversalInOrder(vector<int>& vec, const TreeNode& node) {
    if (node.left) _binaryTreeTraversalInOrder(vec, *node.left);
    vec.emplace_back(node.val);
    if (node.right) _binaryTreeTraversalInOrder(vec, *node.right);
}

BinaryTreeTraversalOrderFunctionType InOrder = _binaryTreeTraversalInOrder;

void _binaryTreeTraversalPostOrder(vector<int>& vec, const TreeNode& node) {
    if (node.left) _binaryTreeTraversalPostOrder(vec, *node.left);
    if (node.right) _binaryTreeTraversalPostOrder(vec, *node.right);
    vec.emplace_back(node.val);
}

BinaryTreeTraversalOrderFunctionType PostOrder = _binaryTreeTraversalPostOrder;

void _binaryTreeTraversalLevelOrder(vector<int>& vec, const TreeNode& node, int layer = 0) {
    auto isLeave = node.left == nullptr && node.right == nullptr;
    vec.emplace_back(node.val);

}

vector<int> treeTraversal(TreeNode& rootNode, BinaryTreeTraversalOrderFunctionType order) {
    vector<int> vec;
    order(vec, rootNode);
    return move(vec);
}

int main() {
    cout << "sizeof(" << NAME_TO_STRING(TreeNode) "): " << sizeof(TreeNode) << endl;
    TreeNode root(17);
    TreeNode leaves[6] = {2, 3, 4, 5, 6, 7};
    assignLeavesOfTreeNode(root, leaves[0], leaves[1]);
    assignLeavesOfTreeNode(leaves[0], leaves[2], leaves[3]);
    assignLeavesOfTreeNode(leaves[1], leaves[4], leaves[5]);
    auto ret = treeTraversal(root, PreOrder);
    print_stl_container_element_with_newline(ret);
    return 0;
}