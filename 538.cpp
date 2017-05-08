#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* convertBST(TreeNode* root) {
    if (!root) return nullptr;

    std::function<int(TreeNode*, int)> recursive = [&](TreeNode* n, int weight) -> int {
        int rightWeight(0), leftWeight(0);
        // We calculate the weight of the right hand
        if (n->right)
            rightWeight = recursive(n->right, weight);
        // We calculate the weight of the left hand, and also assign the weight,
        // n->val and right hand weight to the left hand
        if (n->left)
            leftWeight = recursive(n->left, weight + n->val + rightWeight);

        int result = n->val + leftWeight + rightWeight;

        n->val += weight + rightWeight;

        return result;
    };

    recursive(root, 0);
    return root;
}
