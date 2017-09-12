#include <functional>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int findSecondMinimumValue(TreeNode* root) {
    // Find the smallest child that is bigger than root->val
    if (root->left == nullptr && root->right == nullptr) {
        return -1;
    }

    const int rootValue = root->val;
    int value = std::max(root->left->val, root->right->val);
    std::function<void(TreeNode*)> traverse = [&traverse, rootValue, &value] (TreeNode* node) -> void {
        if (node->val > rootValue && node->val <= value) {
            value = node->val;
        }
        if (node->left) {
            traverse(node->left);
            traverse(node->right);
        }
    };
    traverse(root->left);
    traverse(root->right);

    if (value == rootValue) return -1;
    return value;
}
