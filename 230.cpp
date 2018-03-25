#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int k) {
    int min = 0;
    std::function<int(TreeNode*, int)> traverse = [&](TreeNode* node, int v) -> int{
        if (node == nullptr) return 0;
        int nleft = traverse(node->left, v);
        if (nleft == -1)
            return -1;

        if (v == nleft + 1) {
            min = node->val;
            return -1;
        }

        int nright = traverse(node->right, v - nleft - 1);
        if (nright == -1)
            return -1;
        return nleft + nright + 1;
    };
    traverse(root, k);
    return min;
}
