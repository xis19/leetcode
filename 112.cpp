#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;

    std::function<bool(TreeNode*, int)> visitor = [&visitor, sum](TreeNode* n, int s) -> bool {
        int s1 = s + n->val;

        if (n->left == nullptr && n->right == nullptr) {
            return s1 == sum;
        }

        if (n->left && visitor(n->left, s1))
            return true;
        if (n->right && visitor(n->right, s1))
            return true;
        return false;
    };

    return visitor(root, 0);
}
