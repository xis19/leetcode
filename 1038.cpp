#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* bstToGst(TreeNode* root) {
    int totalSum(0);
    std::function<void(TreeNode*)> sum = [&sum, &totalSum](TreeNode* n) {
        if (n == nullptr) return;
        totalSum += n->val;
        sum(n->left);
        sum(n->right);
    };
    sum(root);

    int leftSum(0);
    std::function<void(TreeNode*)> update = [&update, &leftSum, totalSum](TreeNode* n) {
        if (n == nullptr) return;
        const int V = n->val;
        update(n->left);
        n->val = totalSum - leftSum;
        leftSum += V;
        update(n->right);
    };

    update(root);

    return root;
}
