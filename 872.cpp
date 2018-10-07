#include <functional>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::queue<int> valueQueue;

    std::function<void(TreeNode*)> insert = [&](TreeNode* node) -> void {
        if (!node->left && !node->right) {
            valueQueue.push(node->val);
        } else {
            if (node->left) {
                insert(node->left);
            }
            if (node->right) {
                insert(node->right);
            }
        }
    };

    std::function<bool(TreeNode*)> validate = [&](TreeNode* node) -> bool {
        if (!node->left && !node->right) {
            if (valueQueue.front() != node->val) {
                return false;
            }
            valueQueue.pop();
            return true;
        }

        bool result = true;
        if (node->left) result &= validate(node->left);
        if (node->right) result &= validate(node->right);

        return result;
    };

    insert(root1);
    return validate(root2);
}
