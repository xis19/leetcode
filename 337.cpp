#include <functional>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int rob(TreeNode* root) {
    // first -> include this node
    // second -> exclude this node
    std::function<std::pair<int, int>(TreeNode*)> traverse = [&traverse](TreeNode* n) -> std::pair<int, int> {
        if (n == nullptr) {
            return std::make_pair(0, 0);
        }

        auto left = traverse(n->left);
        auto right = traverse(n->right);

        // If we include this node, then two child nodes should be excluded
        auto includeThis = left.second + right.second + n->val;
        // Otherwise, the two child nodes can be both included or excluded
        auto excludeThis = std::max(left.first, left.second) + std::max(right.first, right.second);

        return std::make_pair(includeThis, excludeThis);
    };

    auto result = traverse(root);
    return std::max(result.first, result.second);
}
