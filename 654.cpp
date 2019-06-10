#include <algorithm>
#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* constructMaximumBinaryTree(const std::vector<int>& nums) {
    if (nums.size() == 0) return 0;

    typedef decltype(nums.begin()) iterator_t;
    std::function<TreeNode*(iterator_t, iterator_t)> construct = [&construct](iterator_t l, iterator_t r) -> TreeNode* {
        iterator_t max_iter = std::max_element(l, r);

        // Empty range
        if (max_iter == r) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(*max_iter);
        node->left = construct(l, max_iter);
        node->right = construct(std::next(max_iter), r);

        return node;
    };

    return construct(nums.begin(), nums.end());
}
