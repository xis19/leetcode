#include <limits>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int largestBSTSubtree(TreeNode* root) {
    typedef struct {
        int max;
        int min;
        int size;
        bool null;
        bool isBST;
    } result_t;

    int maxBST = 0;

    std::function<result_t(TreeNode*)> traverse = [&traverse, &maxBST](TreeNode* n) -> result_t {
        if (n == nullptr) {
            return result_t{0, 0, 0, true, true};
        }

        auto l = traverse(n->left);
        auto r = traverse(n->right);
        result_t result{n->val, n->val, 1, false, true};
        if (l.isBST && r.isBST) {
            if (!l.null) {
                if (l.max < n->val) {
                    result.min = l.min;
                } else {
                    result.isBST = false;
                }
            }
            if (!r.null) {
                if (r.min > n->val) {
                    result.max = r.max;
                } else {
                    result.isBST = false;
                }
            }
            result.size += l.size + r.size;
        } else {
            result.isBST = false;
        }

        if (result.isBST) maxBST = std::max(result.size, maxBST);
        return result;
    };

    traverse(root);
    return maxBST;
}
