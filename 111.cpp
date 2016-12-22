#include <functional>
#include <limits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int minDepth = std::numeric_limits<int>::max();
    std::function<void(TreeNode*, int)> traverser = [&](TreeNode* n, int d) {
        if (d >= minDepth || n == nullptr) {
            return;
        }

        if (!(n->left || n->right)) {
            minDepth = std::min(d, minDepth);
            return;
        }
        traverser(n->left, d + 1);
        traverser(n->right, d + 1);
    };

    traverser(root, 1);
    return minDepth;
}
