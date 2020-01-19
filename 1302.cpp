#include <functional>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int deepestLeavesSum(TreeNode* root) {
    std::map<int, int> depthSum;
    std::function<void(TreeNode*, int)> traverse = [&depthSum, &traverse](TreeNode* n, int depth) {
        if (n == nullptr) {
            return;
        }
        if (depthSum.find(depth) == depthSum.end()) {
            depthSum[depth] = 0;
        }
        depthSum[depth] += n->val;
        traverse(n->left, depth + 1);
        traverse(n->right, depth + 1);
    };

    traverse(root, 0);
    return std::prev(depthSum.end())->second;
}
