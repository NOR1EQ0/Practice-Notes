#include <bits/stdc++.h>
#include "../utils/print"
#define NAME_TO_STRING(v) #v

using namespace std;

/**
 * 最简单的二叉树节点结构体。
 * pTreeNode 为该结构体的指针类型别名。
 */
typedef struct _BinaryTreeNode {
    int val;
    _BinaryTreeNode* left;
    _BinaryTreeNode* right;
    constexpr _BinaryTreeNode(int value, _BinaryTreeNode* lptr = nullptr, _BinaryTreeNode* rptr = nullptr) : val(value), left(lptr), right(rptr) {};
    constexpr _BinaryTreeNode() : val(int()), left(nullptr), right(nullptr) {};
} TreeNode, BinaryTreeNode, * pTreeNode, * pBinaryTreeNode;

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

using BinaryTreeTraversalOrderFunctionType = void(*)(vector<int>&, const TreeNode&);

// Binary tree traversal pre-order function
void _binaryTreeTraversalPreOrder(vector<int>& vec, const TreeNode& node) {
    if (&node == nullptr) return;
    vec.emplace_back(node.val);
    if (node.left) _binaryTreeTraversalPreOrder(vec, *node.left);
    if (node.right) _binaryTreeTraversalPreOrder(vec, *node.right);
}
BinaryTreeTraversalOrderFunctionType PreOrder = _binaryTreeTraversalPreOrder;

// Binary tree traversal in-order function
void _binaryTreeTraversalInOrder(vector<int>& vec, const TreeNode& node) {
    if (&node == nullptr) return;
    if (node.left) _binaryTreeTraversalInOrder(vec, *node.left);
    vec.emplace_back(node.val);
    if (node.right) _binaryTreeTraversalInOrder(vec, *node.right);
}
BinaryTreeTraversalOrderFunctionType InOrder = _binaryTreeTraversalInOrder;

// Binary tree traversal post-order function
void _binaryTreeTraversalPostOrder(vector<int>& vec, const TreeNode& node) {
    if (&node == nullptr) return;
    if (node.left) _binaryTreeTraversalPostOrder(vec, *node.left);
    if (node.right) _binaryTreeTraversalPostOrder(vec, *node.right);
    vec.emplace_back(node.val);
}
BinaryTreeTraversalOrderFunctionType PostOrder = _binaryTreeTraversalPostOrder;

// Binary tree traversal level-order function
void _binaryTreeTraversalLevelOrder(vector<int>& vec, const TreeNode& node) {
    if (&node == nullptr) return;
    queue<pTreeNode> q;
    q.push(const_cast<pTreeNode>(&node));
    while (!q.empty()) {
        pTreeNode current = q.front();
        q.pop();
        vec.emplace_back(current->val);
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}
BinaryTreeTraversalOrderFunctionType LevelOrder = _binaryTreeTraversalLevelOrder;

vector<int> treeTraversal(TreeNode& rootNode, BinaryTreeTraversalOrderFunctionType order) {
    vector<int> vec;
    order(vec, rootNode);
    vec.shrink_to_fit();
    return vec;
}

// 数组实现的二叉树
typedef struct _arrayBinaryTree {
    _arrayBinaryTree(vector<int> vec) {
        this->tree = vec;
    }

    inline size_t size() const {
        return this->tree.size();
    }

    int val(int i) {
        if (i < 0 || i >= this->tree.size()) {
            return numeric_limits<int>().max();
        }
        return this->tree.at(i);
    }

    inline int left(int i) {
        return 2 * i + 1;
    }

    inline int right(int i) {
        return 2 * i + 2;
    }

    inline int parent(int i) {
        return (i - 1) / 2;
    }

    vector<int> levelOrder() {
        vector<int> ret;
        ret.reserve(this->tree.size());
        for (const auto i : tree)
            if (i != numeric_limits<int>().max())
                ret.emplace_back(i);
        ret.shrink_to_fit();
        return ret;
    }

    vector<int> preOrder() {
        return dfsVector(ORDER::pre);
    }

    vector<int> inOrder() {
        return dfsVector(ORDER::in);
    }

    vector<int> postOrder() {
        return dfsVector(ORDER::post);
    }
private:
    vector<int> tree;
    enum ORDER : char {
        pre = 0, in, post
    };
    void dfs(int i, char order, vector<int>& vec) {
        if (vec[i] == numeric_limits<int>().max()) return;

        if (order == this->ORDER::pre) vec.emplace_back(this->val(i));
        dfs(left(i), order, vec);
        if (order == this->ORDER::in) vec.emplace_back(this->val(i));
        dfs(right(i), order, vec);
        if (order == this->ORDER::post) vec.emplace_back(this->val(i));
    }
    inline vector<int> dfsVector(char order) {
        vector<int> vec;
        vec.reserve(this->tree.size());
        dfs(0, order, vec);
        vec.shrink_to_fit();
        return vec;
    }
} ArrayBinaryTree;

// 二叉搜索树
typedef struct _binarySearchTree {
    BinaryTreeNode* root;

    TreeNode* search(int val, bool stackBuffer = false) noexcept {
        if (stackBuffer) {
            this->_eraseStackBuffer();
        }
        TreeNode* cur = this->root;
        while (cur != nullptr) {
            if (stackBuffer) {
                this->_stackBuffer.emplace(cur);
            }
            if (val < cur->val) cur = cur->left;
            else if (val > cur->val) cur = cur->right;
            else return cur;
        }
        return nullptr;
    }

    void insert(int val) noexcept {
        if (root == nullptr) {
            root = new TreeNode(val);
            return;
        }
        TreeNode* cur = this->root, * pre = nullptr;
        while (cur != nullptr) {
            if (cur->val == val) return;
            pre = cur;
            if (cur->val > val) cur = cur->right;
            else cur = cur->left;
        }
        if (pre->val > val) pre->right = new TreeNode(val);
        else pre->left = new TreeNode(val);
    }

    bool remove(int val) {
        if (this->root == nullptr) return false; // 若真的需要删除根节点，需要寻找中值重新构造一个新 BST。在该类不应实现此功能。
        auto resultNode = this->search(val, true);
        auto pre = (this->_stackBuffer.pop(), this->_stackBuffer.top());
        if (resultNode == nullptr) return false;
        if (resultNode->left == nullptr || resultNode->right == nullptr) {
            TreeNode* child = resultNode->left != nullptr ? resultNode->left : resultNode->right;
            if (resultNode != nullptr) {
                if (pre->left == resultNode) pre->left = child;
                else pre->right = child;
            }
            delete resultNode;
        } else {
            TreeNode* tmp = resultNode->right;
            while (resultNode != nullptr) {
                tmp = resultNode->left;
            }
            resultNode->val = tmp->val;
            this->remove(tmp->val);
        }
    }

    /// @brief 根据 `node` 构造一个平衡的二叉搜索树
    /// @param node 二叉树根节点
    /// @param order 遍历该二叉树时的遍历方式，默认使用层序遍历。
    _binarySearchTree(TreeNode& node, BinaryTreeTraversalOrderFunctionType order = LevelOrder) : root(nullptr) {
        typedef invoke_result<decltype(this->_globalTreeTraversal), TreeNode&, BinaryTreeTraversalOrderFunctionType>::type TreeTraversalVector;
        typedef TreeTraversalVector::value_type ValueType;
        TreeTraversalVector retVec = this->_globalTreeTraversal(node, order);
        sort(retVec.begin(), retVec.end());
        const size_t len = retVec.size();
        const size_t position = len / 2;
        const ValueType middle = retVec[position];
        this->root = new TreeNode(middle);
        for (int i = 0; i < len; ++i) this->insert(retVec[i]);
    }

    vector<int> treeTraversal() {
        return this->_globalTreeTraversal(*this->root, InOrder);
    }

    ~_binarySearchTree() {
        vector<TreeNode*> ret;
        this->_treePtrTraversal(ret, *this->root);
        ret.erase(ret.begin());
        for (auto i: ret) {
            delete i;
        }
        this->root->val = 0;
    }
private:
    stack<TreeNode*> _stackBuffer;
    void _eraseStackBuffer() { while (!this->_stackBuffer.empty()) this->_stackBuffer.pop(); }
    static constexpr vector<int> (*_globalTreeTraversal)(TreeNode&, BinaryTreeTraversalOrderFunctionType) = ::treeTraversal;
    void _treePtrTraversal(vector<TreeNode*> vec, const TreeNode& node) {
        if (&node == nullptr) return;
        if (node.left) this->_treePtrTraversal(vec, *node.left);
        vec.emplace_back(&node);
        if (node.right) this->_treePtrTraversal(vec, *node.right);
    }
};

int main() {
    cout << "sizeof(" << NAME_TO_STRING(TreeNode) "): " << sizeof(TreeNode) << endl;
    TreeNode root(17);
    TreeNode leaves[6] = { 2, 3, 4, 5, 6, 7 };
    assignLeavesOfTreeNode(root, leaves[0], leaves[1]);
    assignLeavesOfTreeNode(leaves[0], leaves[2], leaves[3]);
    assignLeavesOfTreeNode(leaves[1], leaves[4], leaves[5]);
    auto ret = treeTraversal(root, LevelOrder);
    print_stl_container_element_with_newline(ret);
    return 0;
}