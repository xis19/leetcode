#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findTilt(TreeNode* root) {
    if (!root) return 0;

    std::function<std::pair<int, int>(TreeNode*)> recursive =
            [&recursive](TreeNode* n) -> std::pair<int, int> {
        auto left = n->left ? recursive(n->left) : std::make_pair(0, 0);
        auto right = n->right ? recursive(n->right) : std::make_pair(0, 0);

        return std::make_pair(std::abs(left.second - right.second) + left.first + right.first,
            n->val + left.second + right.second);
    };

    return recursive(root).first;
}
