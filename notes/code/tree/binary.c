#include "../utils/c-all.h"

typedef struct TreeNode {
    int val;
    int height;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

TreeNode* newTreeNode(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    TreeNode* tree = newTreeNode(2);
    TreeNode* n1 = newTreeNode(20);
    TreeNode* n2 = newTreeNode(127);
    tree->left = n1;
    tree->right = n2;
}