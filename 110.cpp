#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBalanced(TreeNode* root) {
    std::function<std::pair<bool, int>(TreeNode*)> balanced = [&](TreeNode* node) -> std::pair<bool, int> {
        if (!node) return std::make_pair(true, 0);
        auto lhs = balanced(node->left);
        auto rhs = balanced(node->right);
        if (!lhs.first || !rhs.first) return std::make_pair(false, -1);
        if (std::abs(lhs.second - rhs.second) <= 1) {
            return std::make_pair(true, std::max(lhs.second, rhs.second) + 1);
        }
        return std::make_pair(false, -1);
    };

    return balanced(root).first;
}
