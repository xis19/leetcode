#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* bstFromPreorder(const std::vector<int>& preorder) {
    typedef decltype(preorder.begin()) iterator_t;
    std::function<TreeNode*(iterator_t, iterator_t)> traverse =
        [&traverse](iterator_t i1, iterator_t i2) -> TreeNode* {
            if (i1 >= i2) return nullptr;
            TreeNode* node = new TreeNode(*i1);
            i1 = std::next(i1);
            auto s = i1;
            for (; s < i2; ++s) {
                if (*s > node->val) {
                    break;
                }
            }
            node->left = traverse(i1, s);
            node->right = traverse(s, i2);
            return node;
        };
    if (preorder.empty()) return nullptr;
    return traverse(preorder.begin(), preorder.end());
}
