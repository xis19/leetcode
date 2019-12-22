#include <algorithm>
#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    std::vector<std::vector<TreeNode*>> history;
    std::vector<TreeNode*> nodes;
    int maxDepth = 0;
    std::function<void(TreeNode*, int)> traverse =
            [&history, &nodes, &maxDepth, &traverse](TreeNode* n, int d) {
        if (n == nullptr) {
            return;
        }

        nodes.push_back(n);
        if (d > maxDepth) {
            history.clear();
            maxDepth = d;
        }
        if (d == maxDepth) {
            history.push_back(nodes);
        }

        traverse(n->left, d + 1);
        traverse(n->right, d + 1);
        nodes.pop_back();
    };

    traverse(root, 0);

    for (int i = 0; i <= maxDepth; ++i) {
        auto first = history[0][i];
        auto same = true;
        for (auto& historyItem: history) {
            if (historyItem[i] != first) {
                same = false;
                break;
            }
        }

        if (!same) {
            return history[0][i - 1];
        }
    }

    return history[0].back();
}

