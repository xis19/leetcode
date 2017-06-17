#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    int depth = 0;
    std::function<void(TreeNode*, int)> visitor = [&depth, &visitor](TreeNode* n, int level) -> void {
        if (n == nullptr) {
            return;
        }

        ++level;
        depth = std::max(depth, level);
        if (n->left) visitor(n->left, level);
        if (n->right) visitor(n->right, level);
    };

    visitor(root, 0);
    return depth;
}
