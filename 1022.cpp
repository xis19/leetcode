#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumRootToLeaf(TreeNode* node) {
    int sum = 0;

    std::function<void(TreeNode*, int v)> traverser = [&sum, &traverser](TreeNode* node, int v) -> void {
        v = v * 2 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            sum += v;
            return;
        }

        if (node->left) traverser(node->left, v);
        if (node->right) traverser(node->right, v);
    };

    traverser(node, 0);
    return sum;
}
