#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int vp = p->val, vq = q->val;
    int min = std::min(vp, vq), max = std::max(vp, vq);
    TreeNode* iter = root;
    while(!(min <= iter->val && max >= iter->val)) {
        if (max < iter->val)
            iter = iter->left;
        if (min > iter->val) {
            iter = iter->right;
        }
    }
    return iter;
}
