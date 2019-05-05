#include <functional>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isCousins(TreeNode* root, int x, int y) {
    std::function<std::pair<TreeNode*, int>(TreeNode*, int, TreeNode*, int)>
            getDepth = [&getDepth](TreeNode* n, int x, TreeNode* parent, int d) -> std::pair<TreeNode*, int> {
        if (n == nullptr) return std::make_pair(nullptr, -1);
        if (n->val == x) return std::make_pair(parent, d);

        auto lval = getDepth(n->left, x, n, d + 1);
        auto rval = getDepth(n->right, x, n, d + 1);

        if (lval.second != -1) return lval;
        if (rval.second != -1) return rval;
        return std::make_pair(nullptr, -1);
    };

    auto xDepth = getDepth(root, x, nullptr, 0);
    auto yDepth = getDepth(root, y, nullptr, 0);
    return (xDepth.first != nullptr &&
            yDepth.first != nullptr &&
            xDepth.first != yDepth.first &&
            xDepth.second == yDepth.second);
}
