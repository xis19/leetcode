#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* t1, TreeNode* t2) {
    std::function<bool(TreeNode*, TreeNode*)> isSame = [&](TreeNode* n1, TreeNode* n2) -> bool {
        int numNulls = (n1 == nullptr) + (n2 == nullptr);
        switch(numNulls) {
            case 2:
                return true;
            case 1:
                return false;
            case 0:
                return n1->val == n2->val && isSame(n1->left, n2->left) && isSame(n1->right, n2->right);
        }
        // Should not reach here
        return false;
    };

    return isSame(t1, t2);
}
