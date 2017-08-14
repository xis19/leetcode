#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int pathSum(TreeNode* root, int sum) {
    int result(0);
    std::vector<int> sums;
    std::function<void(void)> checkSum = [sum, &result, &sums](void) -> void {
        const int L = sums.size();
        int s = 0;
        for(int i = L - 1; i >= 0; --i) {
            s += sums[i];
            result += (s == sum);
        }
    };
    std::function<void(TreeNode*)> traverse = [&sums, &traverse, &checkSum](TreeNode* n) -> void {
        sums.push_back(n->val);
        if (n->left) traverse(n->left);
        if (n->right) traverse(n->right);
        checkSum();
        sums.pop_back();
    };

    if (!root) return result;
    traverse(root);
    return result;
}
