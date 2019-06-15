#include <functional>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int maxDepth = 0;
    int deepestNodesCount = 0;

    // Find the count and depth of most depth nodes
    {
        std::function<void(TreeNode*, int)> find = [&find, &maxDepth, &deepestNodesCount](TreeNode* n, int d) {
            if (n == nullptr) return;

            if (d >= maxDepth) {
                if (d > maxDepth) {
                    maxDepth = d;
                    deepestNodesCount = 0;
                }

                ++deepestNodesCount;
            }

            find(n->left, d + 1);
            find(n->right, d + 1);
        };

        find(root, 0);
    }

    // Traverse again to locate the deepest parent of deepest nodes
    TreeNode* result = nullptr;
    {
        std::function<int(TreeNode*, int)> find = [&find, &result, maxDepth, deepestNodesCount](TreeNode* n, int d) -> int{
            // If found, shortcut.
            if (result != nullptr) return 0;
            if (n == nullptr) return 0;

            int numDeepestNodesInSubTree = 0;
            if (d == maxDepth) {
                numDeepestNodesInSubTree = 1;
            }

            numDeepestNodesInSubTree += find(n->left, d + 1) + find(n->right, d + 1);
            if (numDeepestNodesInSubTree == deepestNodesCount && result == nullptr) {
                result = n;
            }

            return numDeepestNodesInSubTree;
        };

        find(root, 0);
    }

    return result;
}
