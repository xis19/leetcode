#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int distributeCoins(TreeNode* root) {
    // Noticing that
    //          2
    //         /
    //        3
    //       / \
    //      0   0
    //       \
    //        0
    // No matter you do a distribution
    //          2
    //         / \
    //        0
    //       / \
    //      1   1
    //       \
    //        1
    // And then pull one coin from 2 at root, or
    //          2
    //         / \
    //        1
    //       / \
    //      1   1
    //       \
    //        0
    // And pull one coin from 2 at root, you always need 5 steps.
    int numSteps(0);
    std::function<int(TreeNode*)> traverse = [&numSteps, &traverse](TreeNode* n) -> int {
        if (n == nullptr) return 0;

        int leftContribute = traverse(n->left);
        int rightContribute = traverse(n->right);
        numSteps += std::abs(leftContribute);
        numSteps += std::abs(rightContribute);

        int coins = n->val + leftContribute + rightContribute;
        return coins - 1;
    };

    numSteps += std::abs(traverse(root));
    return numSteps;
}
