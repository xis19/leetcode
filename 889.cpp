#include <functional>
#include <unordered_map>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* constructFromPrePost(const std::vector<int> pre, const std::vector<int> post) {
    const int LEN = pre.size();
    if (LEN == 0) return nullptr;

    // Map Tree Node value to the index of pre/post vector
    std::unordered_map<int, int> prePosMapper, postPosMapper;
    for (int i = 0; i < LEN; ++i) {
        prePosMapper[pre[i]] = i;
        postPosMapper[post[i]] = i;
    }

    // Start/end are inclusive
    std::function<TreeNode*(int, int, int, int)> traverse = [&](int preStart, int preEnd, int postStart, int postEnd) -> TreeNode* {
        const int VALUE = pre[preStart];
        TreeNode* node = new TreeNode(VALUE);

        // the element after preStart should be the left child, the element
        // before postEnd should be the right child.
        int lChild = -1, rChild = -1;
        if (preStart < preEnd) {
            lChild = pre[preStart + 1];
        }
        if (postStart < postEnd) {
            rChild = post[postEnd - 1];
        }

        // Special condition -- only one child, in this case lChild has the same
        // value to rChild, take it as lChild
        if (lChild != -1 && lChild == rChild) {
            node->left = traverse(preStart + 1, preEnd, postStart, postEnd - 1);
            return node;
        }

        int preEndLchild = rChild == -1 ? preEnd : prePosMapper[rChild] - 1;
        int postStartRchild = lChild == -1 ? postStart : postPosMapper[lChild] + 1;

        if (lChild != -1) {
            node->left = traverse(preStart + 1, preEndLchild, postStart, postStartRchild - 1);
        }

        if (rChild != -1) {
            node->right = traverse(preEndLchild + 1, preEnd, postStartRchild, postEnd - 1);
        }

        return node;
    };

    return traverse(0, LEN - 1, 0, LEN - 1);
}
