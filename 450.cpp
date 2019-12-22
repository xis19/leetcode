#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    if (root->val < key) {
        root->right = deleteNode(root->right, key);
        return root;
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
        return root;
    }

    // We meet it! We use the rightmost left branch as the root.
    if (root->left == nullptr) {
        return root->right;
    }

    TreeNode* rightMostParent = root->left;
    TreeNode* rightMost = root->left;
    while (rightMost->right != nullptr)
        rightMostParent = rightMost, rightMost = rightMost->right;

    if (rightMost == root->left) {
        root->left->right = root->right;
        return root->left;
    }

    rightMostParent->right = rightMost->left;
    rightMost->left = root->left;
    rightMost->right = root->right;
    return rightMost;
}
