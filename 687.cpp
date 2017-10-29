#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int longestUnivaluePath(TreeNode* root) {
    if (root == nullptr)
        return 0;

    int longest = 0;
    std::function<std::pair<int, int>(TreeNode*)> visitor = [&longest, &visitor](TreeNode* node) -> std::pair<int, int> {
        auto left = node->left == nullptr ? std::make_pair(0, 0) : visitor(node->left);
        auto right = node->right == nullptr ? std::make_pair(0, 0) : visitor(node->right);

        int leftPath = left.first == node->val ? left.second : 0;
        int rightPath = right.first == node->val ? right.second : 0;
        int maxSidePath = std::max(leftPath + 1, rightPath + 1);

        // We need to consider the following situation:
        //
        //          a               a
        //         / \              |
        //        a   a             a
        //                         / \
        //                        a   b
        longest = std::max({longest, leftPath + rightPath + 1, maxSidePath});
        return std::make_pair(node->val, maxSidePath);
    };

    visitor(root);

    // We were calculating nodes in the path, the actual length of path is
    // num nodes - 1
    return longest - 1;
}
