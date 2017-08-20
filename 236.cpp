#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    std::vector<TreeNode*> pHistory, qHistory;
    std::vector<TreeNode*> history;
    bool pFound(false), qFound(false);
    std::function<void(TreeNode*)> visitor = [&](TreeNode* n) -> void {
        if (pFound && qFound) return;
        history.push_back(n);
        if (n == p) {
            pFound = true;
            pHistory = history;
        }
        if (n == q) {
            qFound = true;
            qHistory = history;
        }
        if (n->left) visitor(n->left);
        if (n->right) visitor(n->right);
        history.pop_back();
    };

    visitor(root);
    TreeNode* last = nullptr;
    auto pI = pHistory.begin();
    auto qI = qHistory.begin();
    while(*pI == *qI && pI != pHistory.end() && qI != qHistory.end()) {
        last = *pI;
        ++pI, ++qI;
    }

    return last;
}
