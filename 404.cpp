#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    std::function<int(TreeNode*, bool)> visitor = [&](TreeNode* node, bool isLeft) -> int {
        if (!node->left && !node->right && isLeft) {
            return node->val;
        } else {
            int lNodeLeft = node->left ? visitor(node->left, true) : 0;
            int rNodeLeft = node->right ? visitor(node->right, false) : 0;
            return lNodeLeft + rNodeLeft;
        }
    };

    return root ? visitor(root, false) : 0;
}
